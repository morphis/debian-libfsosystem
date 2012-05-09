/* fsosystem-2.0.vapi generated by valac 0.14.2, do not modify. */

namespace FsoFramework {
	namespace FileSystem {
		[CCode (cheader_filename = "fsosystem.h")]
		public class Path : GLib.Object {
			public Path (string path);
			public bool is_absolute ();
			public bool is_mount_point ();
			public string path { get; private set; }
		}
		[CCode (cheader_filename = "fsosystem.h")]
		public static bool createDirectory (string filename, Posix.mode_t mode);
		[CCode (cheader_filename = "fsosystem.h")]
		public static bool isPresent (string filename);
		[CCode (cheader_filename = "fsosystem.h")]
		public static bool mountFilesystem (string source, string target, string type, Linux.MountFlags flags);
		[CCode (cheader_filename = "fsosystem.h")]
		public static bool mountFilesystemAt (Posix.mode_t mode, string source, string target, string type, Linux.MountFlags flags);
		[CCode (cheader_filename = "fsosystem.h")]
		public static void write (string contents, string filename, bool create = false);
	}
	namespace Kernel {
		[CCode (cheader_filename = "fsosystem.h")]
		public static void insertModule (string filename, string? options = null) throws GLib.Error;
		[CCode (cheader_filename = "fsosystem.h")]
		public static void probeModule (string modulename, string? options = null);
		[CCode (cheader_filename = "fsosystem.h")]
		public static void removeModule (string filename, bool wait = false, bool force = false) throws GLib.Error;
	}
	namespace Network {
		[CCode (cheader_filename = "fsosystem.h")]
		public class Interface {
			protected int fd;
			protected int index;
			protected string name;
			public Interface (string name) throws FsoFramework.Network.Error;
			public void down () throws FsoFramework.Network.Error;
			public void finish ();
			public bool is_up () throws FsoFramework.Network.Error;
			public void up () throws FsoFramework.Network.Error;
		}
		[CCode (cheader_filename = "fsosystem.h")]
		public class WextInterface : FsoFramework.Network.Interface {
			public WextInterface (string name) throws FsoFramework.Network.Error;
			public void set_power (bool on) throws FsoFramework.Network.Error;
		}
		[CCode (cheader_filename = "fsosystem.h")]
		public errordomain Error {
			INTERNAL_ERROR
		}
	}
	[CCode (cheader_filename = "fsosystem.h")]
	public class Wakelock : GLib.Object {
		public Wakelock (string name);
		public void acquire ();
		public void release ();
		public bool acquired { get; private set; }
		public string name { get; private set; }
	}
}
[CCode (cheader_filename = "fsosystem.h")]
public errordomain SystemError {
	ERROR
}
