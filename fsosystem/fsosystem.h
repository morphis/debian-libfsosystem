/* fsosystem.h generated by valac 0.14.2, the Vala compiler, do not modify */


#ifndef __FSOSYSTEM_H__
#define __FSOSYSTEM_H__

#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <linux/fs.h>

G_BEGIN_DECLS


#define FSO_FRAMEWORK_NETWORK_TYPE_INTERFACE (fso_framework_network_interface_get_type ())
#define FSO_FRAMEWORK_NETWORK_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_NETWORK_TYPE_INTERFACE, FsoFrameworkNetworkInterface))
#define FSO_FRAMEWORK_NETWORK_INTERFACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_NETWORK_TYPE_INTERFACE, FsoFrameworkNetworkInterfaceClass))
#define FSO_FRAMEWORK_NETWORK_IS_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_NETWORK_TYPE_INTERFACE))
#define FSO_FRAMEWORK_NETWORK_IS_INTERFACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_NETWORK_TYPE_INTERFACE))
#define FSO_FRAMEWORK_NETWORK_INTERFACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_NETWORK_TYPE_INTERFACE, FsoFrameworkNetworkInterfaceClass))

typedef struct _FsoFrameworkNetworkInterface FsoFrameworkNetworkInterface;
typedef struct _FsoFrameworkNetworkInterfaceClass FsoFrameworkNetworkInterfaceClass;
typedef struct _FsoFrameworkNetworkInterfacePrivate FsoFrameworkNetworkInterfacePrivate;

#define FSO_FRAMEWORK_NETWORK_TYPE_WEXT_INTERFACE (fso_framework_network_wext_interface_get_type ())
#define FSO_FRAMEWORK_NETWORK_WEXT_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_NETWORK_TYPE_WEXT_INTERFACE, FsoFrameworkNetworkWextInterface))
#define FSO_FRAMEWORK_NETWORK_WEXT_INTERFACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_NETWORK_TYPE_WEXT_INTERFACE, FsoFrameworkNetworkWextInterfaceClass))
#define FSO_FRAMEWORK_NETWORK_IS_WEXT_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_NETWORK_TYPE_WEXT_INTERFACE))
#define FSO_FRAMEWORK_NETWORK_IS_WEXT_INTERFACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_NETWORK_TYPE_WEXT_INTERFACE))
#define FSO_FRAMEWORK_NETWORK_WEXT_INTERFACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_NETWORK_TYPE_WEXT_INTERFACE, FsoFrameworkNetworkWextInterfaceClass))

typedef struct _FsoFrameworkNetworkWextInterface FsoFrameworkNetworkWextInterface;
typedef struct _FsoFrameworkNetworkWextInterfaceClass FsoFrameworkNetworkWextInterfaceClass;
typedef struct _FsoFrameworkNetworkWextInterfacePrivate FsoFrameworkNetworkWextInterfacePrivate;

#define FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH (fso_framework_file_system_path_get_type ())
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPath))
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPathClass))
#define FSO_FRAMEWORK_FILE_SYSTEM_IS_PATH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH))
#define FSO_FRAMEWORK_FILE_SYSTEM_IS_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH))
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPathClass))

typedef struct _FsoFrameworkFileSystemPath FsoFrameworkFileSystemPath;
typedef struct _FsoFrameworkFileSystemPathClass FsoFrameworkFileSystemPathClass;
typedef struct _FsoFrameworkFileSystemPathPrivate FsoFrameworkFileSystemPathPrivate;

#define FSO_FRAMEWORK_TYPE_WAKELOCK (fso_framework_wakelock_get_type ())
#define FSO_FRAMEWORK_WAKELOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelock))
#define FSO_FRAMEWORK_WAKELOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelockClass))
#define FSO_FRAMEWORK_IS_WAKELOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_WAKELOCK))
#define FSO_FRAMEWORK_IS_WAKELOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_WAKELOCK))
#define FSO_FRAMEWORK_WAKELOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelockClass))

typedef struct _FsoFrameworkWakelock FsoFrameworkWakelock;
typedef struct _FsoFrameworkWakelockClass FsoFrameworkWakelockClass;
typedef struct _FsoFrameworkWakelockPrivate FsoFrameworkWakelockPrivate;

typedef enum  {
	SYSTEM_ERROR_ERROR
} SystemError;
#define SYSTEM_ERROR system_error_quark ()
typedef enum  {
	FSO_FRAMEWORK_NETWORK_ERROR_INTERNAL_ERROR
} FsoFrameworkNetworkError;
#define FSO_FRAMEWORK_NETWORK_ERROR fso_framework_network_error_quark ()
struct _FsoFrameworkNetworkInterface {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FsoFrameworkNetworkInterfacePrivate * priv;
	gint fd;
	gchar* name;
	gint index;
};

struct _FsoFrameworkNetworkInterfaceClass {
	GTypeClass parent_class;
	void (*finalize) (FsoFrameworkNetworkInterface *self);
};

struct _FsoFrameworkNetworkWextInterface {
	FsoFrameworkNetworkInterface parent_instance;
	FsoFrameworkNetworkWextInterfacePrivate * priv;
};

struct _FsoFrameworkNetworkWextInterfaceClass {
	FsoFrameworkNetworkInterfaceClass parent_class;
};

struct _FsoFrameworkFileSystemPath {
	GObject parent_instance;
	FsoFrameworkFileSystemPathPrivate * priv;
};

struct _FsoFrameworkFileSystemPathClass {
	GObjectClass parent_class;
};

struct _FsoFrameworkWakelock {
	GObject parent_instance;
	FsoFrameworkWakelockPrivate * priv;
};

struct _FsoFrameworkWakelockClass {
	GObjectClass parent_class;
};


GQuark system_error_quark (void);
void fso_framework_kernel_insertModule (const gchar* filename, const gchar* options, GError** error);
void fso_framework_kernel_removeModule (const gchar* filename, gboolean wait, gboolean force, GError** error);
void fso_framework_kernel_probeModule (const gchar* modulename, const gchar* options);
GQuark fso_framework_network_error_quark (void);
gpointer fso_framework_network_interface_ref (gpointer instance);
void fso_framework_network_interface_unref (gpointer instance);
GParamSpec* fso_framework_network_param_spec_interface (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_framework_network_value_set_interface (GValue* value, gpointer v_object);
void fso_framework_network_value_take_interface (GValue* value, gpointer v_object);
gpointer fso_framework_network_value_get_interface (const GValue* value);
GType fso_framework_network_interface_get_type (void) G_GNUC_CONST;
FsoFrameworkNetworkInterface* fso_framework_network_interface_new (const gchar* name, GError** error);
FsoFrameworkNetworkInterface* fso_framework_network_interface_construct (GType object_type, const gchar* name, GError** error);
void fso_framework_network_interface_up (FsoFrameworkNetworkInterface* self, GError** error);
gboolean fso_framework_network_interface_is_up (FsoFrameworkNetworkInterface* self, GError** error);
void fso_framework_network_interface_down (FsoFrameworkNetworkInterface* self, GError** error);
void fso_framework_network_interface_finish (FsoFrameworkNetworkInterface* self);
GType fso_framework_network_wext_interface_get_type (void) G_GNUC_CONST;
FsoFrameworkNetworkWextInterface* fso_framework_network_wext_interface_new (const gchar* name, GError** error);
FsoFrameworkNetworkWextInterface* fso_framework_network_wext_interface_construct (GType object_type, const gchar* name, GError** error);
void fso_framework_network_wext_interface_set_power (FsoFrameworkNetworkWextInterface* self, gboolean on, GError** error);
gboolean fso_framework_file_system_isPresent (const gchar* filename);
gboolean fso_framework_file_system_createDirectory (const gchar* filename, mode_t mode);
gboolean fso_framework_file_system_mountFilesystem (const gchar* source, const gchar* target, const gchar* type, unsigned long int flags);
gboolean fso_framework_file_system_mountFilesystemAt (mode_t mode, const gchar* source, const gchar* target, const gchar* type, unsigned long int flags);
void fso_framework_file_system_write (const gchar* contents, const gchar* filename, gboolean create);
GType fso_framework_file_system_path_get_type (void) G_GNUC_CONST;
FsoFrameworkFileSystemPath* fso_framework_file_system_path_new (const gchar* path);
FsoFrameworkFileSystemPath* fso_framework_file_system_path_construct (GType object_type, const gchar* path);
gboolean fso_framework_file_system_path_is_absolute (FsoFrameworkFileSystemPath* self);
gboolean fso_framework_file_system_path_is_mount_point (FsoFrameworkFileSystemPath* self);
const gchar* fso_framework_file_system_path_get_path (FsoFrameworkFileSystemPath* self);
GType fso_framework_wakelock_get_type (void) G_GNUC_CONST;
FsoFrameworkWakelock* fso_framework_wakelock_new (const gchar* name);
FsoFrameworkWakelock* fso_framework_wakelock_construct (GType object_type, const gchar* name);
void fso_framework_wakelock_acquire (FsoFrameworkWakelock* self);
void fso_framework_wakelock_release (FsoFrameworkWakelock* self);
const gchar* fso_framework_wakelock_get_name (FsoFrameworkWakelock* self);
gboolean fso_framework_wakelock_get_acquired (FsoFrameworkWakelock* self);


G_END_DECLS

#endif
