using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Newtonsoft.Json.Linq;

namespace Packer {
    internal class Program {
        private static void Main(string[] args) {
            if (args.Length <= 0) {
                Quit("No Qt bin path supplied");
            }

            _ = new Program(args[0]);
        }

        private Program(string qtBinPath) {
            var configJson = FindConfig();
            if (configJson == null) Quit();

            var binaryPath = FindBinary();
            if(binaryPath == null) Quit("Unable to locate binary");
            Console.WriteLine($"Located binary at {binaryPath}");

            var versionInfo = FileVersionInfo.GetVersionInfo(binaryPath ?? throw new InvalidOperationException());

            var newBinaryName = binaryPath.Replace("-V", $"-{versionInfo.ProductVersion}");
            var newBinaryInfo = new FileInfo(newBinaryName);
            Console.WriteLine($"New binary name: {newBinaryInfo.Name}");

            var releaseDir = Path.Combine(Directory.GetCurrentDirectory(), "packed");
            Console.WriteLine(releaseDir);
            if (Directory.Exists(releaseDir)) {
                Console.WriteLine("pack dir exists, deleting");
                Console.WriteLine(releaseDir);
                Directory.Delete(releaseDir, true);
            }

            if (!Directory.Exists(releaseDir)) {
                Console.WriteLine("creating pack dir");
                Console.WriteLine(releaseDir);
                Directory.CreateDirectory(releaseDir);
            }

            Console.WriteLine("Copying binary");
            File.Copy(binaryPath, Path.Combine(releaseDir, newBinaryInfo.Name));

            Console.WriteLine("Setting version to json");
            configJson["version"] = versionInfo.ProductVersion;

            Console.WriteLine("Saving config.json");
            File.WriteAllText(Path.Combine(releaseDir, "config.json"), configJson.ToString());

            Console.WriteLine("Copying ssl libs");
            var packagesPath = FindPackages();
            Console.WriteLine($"Packagespath: {packagesPath}");
            var libeay = Path.Combine(packagesPath, "libeay32.dll").AbsolutePath();
            var ssleay = Path.Combine(packagesPath, "ssleay32.dll").AbsolutePath();
            if(!File.Exists(libeay)) Quit("libeay32.dll not found");
            if(!File.Exists(ssleay)) Quit("ssleay32.dll not found");
            File.Copy(libeay, Path.Combine(releaseDir, "libeay32.dll"));
            File.Copy(ssleay, Path.Combine(releaseDir, "ssleay32.dll"));

            var qtLibs = new [] {
                Path.Combine(qtBinPath, "bin", "Qt5Core.dll"),
                Path.Combine(qtBinPath, "bin", "Qt5Gui.dll"),
                Path.Combine(qtBinPath, "bin", "Qt5Network.dll"),
                Path.Combine(qtBinPath, "bin", "Qt5Svg.dll"),
                Path.Combine(qtBinPath, "bin", "Qt5Widgets.dll")
            };

            Console.WriteLine("Copying qt libs");

            foreach (var qtLib in qtLibs) {
                if(!File.Exists(qtLib)) Quit($"{qtLib} not found");
            }

            foreach (var qtLib in qtLibs) {
                File.Copy(qtLib, Path.Combine(releaseDir, new FileInfo(qtLib).Name));
            }

            var qtPlatformPlugin = Path.Combine(qtBinPath, "plugins", "platforms", "qwindows.dll");
            if (!File.Exists(qtPlatformPlugin)) {
                Quit($"{qtPlatformPlugin} not found");
            }

            if (!Directory.Exists(Path.Combine(releaseDir, "platforms"))) {
                Directory.CreateDirectory(Path.Combine(releaseDir, "platforms"));
            }

            File.Copy(qtPlatformPlugin, Path.Combine(releaseDir, "platforms", "qwindows.dll"));

            Console.WriteLine("All done");
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
            Process.Start(releaseDir);
            Environment.Exit(0);
        }

        private static JObject FindConfig() {
            var currentPath = System.Reflection.Assembly.GetEntryAssembly().Location;
            while (currentPath.Contains("Packer")) currentPath = Path.Combine(currentPath, "..").AbsolutePath();
            while (!Directory.Exists(Path.Combine(currentPath, "src"))) {
                if (Directory.GetParent(currentPath) == null) break;
                currentPath = Path.Combine(currentPath, "..");
            }

            var configJsonPath = Path.Combine(currentPath, "src", "config.json").AbsolutePath();
            if (File.Exists(configJsonPath)) {
                Console.WriteLine($"Located config.json at {configJsonPath}");
                return JObject.Parse(File.ReadAllText(configJsonPath));
            }

            Console.WriteLine("Unable to locate config.json");
            return null;
        }

        private static string FindBinary() {
            var currentPath = System.Reflection.Assembly.GetEntryAssembly().Location;
            while (currentPath.Contains("Packer")) currentPath = Path.Combine(currentPath, "..").AbsolutePath();
            while (!Directory.Exists(Path.Combine(currentPath, "bin"))) {
                if (Directory.GetParent(currentPath) == null) break;
                currentPath = Path.Combine(currentPath, "..");
            }

            currentPath = Path.Combine(currentPath, "bin", "x64", "Release").AbsolutePath();

            if (Directory.Exists(currentPath))
                return (from file in Directory.GetFiles(currentPath)
                    select new FileInfo(file)
                    into finfo
                    where finfo.Extension == ".exe"
                    select finfo.FullName).FirstOrDefault();

            return null;
        }

        private static string FindPackages() {
            var currentPath = System.Reflection.Assembly.GetEntryAssembly().Location;
            while (currentPath.Contains("Packer")) currentPath = Path.Combine(currentPath, "..").AbsolutePath();
            while (!Directory.Exists(Path.Combine(currentPath, "packages"))) {
                if (Directory.GetParent(currentPath) == null) break;
                currentPath = Path.Combine(currentPath, "..");
            }

            return Path.Combine(currentPath, "packages").AbsolutePath();
        }

        private static void Quit(string msg = null) {
            if(msg != null) Console.WriteLine(msg);
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
            Environment.Exit(0);
        }
    }
}
