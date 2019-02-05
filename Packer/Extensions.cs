using System.IO;

namespace Packer {
    public static class Extensions {
        public static string AbsolutePath(this string str) {
            return Path.GetFullPath(str);
        }
    }
}
