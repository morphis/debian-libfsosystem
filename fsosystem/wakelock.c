/* wakelock.c generated by valac 0.14.2, the Vala compiler
 * generated from wakelock.vala, do not modify */

/*
 * Copyright (C) 2011 Simon Busch <morphis@gravedo.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define FSO_FRAMEWORK_TYPE_WAKELOCK (fso_framework_wakelock_get_type ())
#define FSO_FRAMEWORK_WAKELOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelock))
#define FSO_FRAMEWORK_WAKELOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelockClass))
#define FSO_FRAMEWORK_IS_WAKELOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_WAKELOCK))
#define FSO_FRAMEWORK_IS_WAKELOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_WAKELOCK))
#define FSO_FRAMEWORK_WAKELOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelockClass))

typedef struct _FsoFrameworkWakelock FsoFrameworkWakelock;
typedef struct _FsoFrameworkWakelockClass FsoFrameworkWakelockClass;
typedef struct _FsoFrameworkWakelockPrivate FsoFrameworkWakelockPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FsoFrameworkWakelock {
	GObject parent_instance;
	FsoFrameworkWakelockPrivate * priv;
};

struct _FsoFrameworkWakelockClass {
	GObjectClass parent_class;
};

struct _FsoFrameworkWakelockPrivate {
	gboolean wakelocks_supported;
	gchar* _name;
	gboolean _acquired;
};


static gpointer fso_framework_wakelock_parent_class = NULL;

GType fso_framework_wakelock_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_WAKELOCK_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_TYPE_WAKELOCK, FsoFrameworkWakelockPrivate))
enum  {
	FSO_FRAMEWORK_WAKELOCK_DUMMY_PROPERTY,
	FSO_FRAMEWORK_WAKELOCK_NAME,
	FSO_FRAMEWORK_WAKELOCK_ACQUIRED
};
#define FSO_FRAMEWORK_WAKELOCK_sysfs_wk_lock_path "/sys/power/wake_lock"
#define FSO_FRAMEWORK_WAKELOCK_sysfs_wk_unlock_path "/sys/power/wake_unlock"
FsoFrameworkWakelock* fso_framework_wakelock_new (const gchar* name);
FsoFrameworkWakelock* fso_framework_wakelock_construct (GType object_type, const gchar* name);
static void fso_framework_wakelock_set_name (FsoFrameworkWakelock* self, const gchar* value);
gboolean fso_framework_file_system_isPresent (const gchar* filename);
void fso_framework_wakelock_acquire (FsoFrameworkWakelock* self);
void fso_framework_file_system_write (const gchar* contents, const gchar* filename, gboolean create);
const gchar* fso_framework_wakelock_get_name (FsoFrameworkWakelock* self);
void fso_framework_wakelock_release (FsoFrameworkWakelock* self);
gboolean fso_framework_wakelock_get_acquired (FsoFrameworkWakelock* self);
static void fso_framework_wakelock_set_acquired (FsoFrameworkWakelock* self, gboolean value);
static void fso_framework_wakelock_finalize (GObject* obj);
static void _vala_fso_framework_wakelock_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_fso_framework_wakelock_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


/**
     * Setup up the wakelock with a specific name.
     */
FsoFrameworkWakelock* fso_framework_wakelock_construct (GType object_type, const gchar* name) {
	FsoFrameworkWakelock * self = NULL;
	const gchar* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp4_;
	g_return_val_if_fail (name != NULL, NULL);
	self = (FsoFrameworkWakelock*) g_object_new (object_type, NULL);
	_tmp0_ = name;
	fso_framework_wakelock_set_name (self, _tmp0_);
	_tmp2_ = fso_framework_file_system_isPresent (FSO_FRAMEWORK_WAKELOCK_sysfs_wk_lock_path);
	if (_tmp2_) {
		gboolean _tmp3_ = FALSE;
		_tmp3_ = fso_framework_file_system_isPresent (FSO_FRAMEWORK_WAKELOCK_sysfs_wk_unlock_path);
		_tmp1_ = _tmp3_;
	} else {
		_tmp1_ = FALSE;
	}
	_tmp4_ = _tmp1_;
	self->priv->wakelocks_supported = _tmp4_;
	return self;
}


FsoFrameworkWakelock* fso_framework_wakelock_new (const gchar* name) {
	return fso_framework_wakelock_construct (FSO_FRAMEWORK_TYPE_WAKELOCK, name);
}


/**
     * Acquire the wakelock; it will prevent the system from being suspended now!
     */
void fso_framework_wakelock_acquire (FsoFrameworkWakelock* self) {
	gboolean _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->wakelocks_supported;
	if (!_tmp0_) {
		return;
	}
	_tmp1_ = self->priv->_name;
	fso_framework_file_system_write (_tmp1_, FSO_FRAMEWORK_WAKELOCK_sysfs_wk_lock_path, FALSE);
}


/**
     * Release the wakelock; it will not prevent the system from going into suspend state
     * anymore.
     */
void fso_framework_wakelock_release (FsoFrameworkWakelock* self) {
	gboolean _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->wakelocks_supported;
	if (!_tmp0_) {
		return;
	}
	_tmp1_ = self->priv->_name;
	fso_framework_file_system_write (_tmp1_, FSO_FRAMEWORK_WAKELOCK_sysfs_wk_unlock_path, FALSE);
}


const gchar* fso_framework_wakelock_get_name (FsoFrameworkWakelock* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


static void fso_framework_wakelock_set_name (FsoFrameworkWakelock* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
	g_object_notify ((GObject *) self, "name");
}


gboolean fso_framework_wakelock_get_acquired (FsoFrameworkWakelock* self) {
	gboolean result;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_acquired;
	result = _tmp0_;
	return result;
}


static void fso_framework_wakelock_set_acquired (FsoFrameworkWakelock* self, gboolean value) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_acquired = _tmp0_;
	g_object_notify ((GObject *) self, "acquired");
}


static void fso_framework_wakelock_class_init (FsoFrameworkWakelockClass * klass) {
	fso_framework_wakelock_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoFrameworkWakelockPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_fso_framework_wakelock_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_fso_framework_wakelock_set_property;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_wakelock_finalize;
	/**
	     * Name of the wakelock which is used to register the wakelock with the kernel.
	     */
	g_object_class_install_property (G_OBJECT_CLASS (klass), FSO_FRAMEWORK_WAKELOCK_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	/**
	     * Current state of the wakelock. True when the wakelock is acquired and false if not.
	     */
	g_object_class_install_property (G_OBJECT_CLASS (klass), FSO_FRAMEWORK_WAKELOCK_ACQUIRED, g_param_spec_boolean ("acquired", "acquired", "acquired", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void fso_framework_wakelock_instance_init (FsoFrameworkWakelock * self) {
	gchar* _tmp0_;
	self->priv = FSO_FRAMEWORK_WAKELOCK_GET_PRIVATE (self);
	self->priv->wakelocks_supported = FALSE;
	_tmp0_ = g_strdup ("unknown");
	self->priv->_name = _tmp0_;
	self->priv->_acquired = FALSE;
}


static void fso_framework_wakelock_finalize (GObject* obj) {
	FsoFrameworkWakelock * self;
	self = FSO_FRAMEWORK_WAKELOCK (obj);
	_g_free0 (self->priv->_name);
	G_OBJECT_CLASS (fso_framework_wakelock_parent_class)->finalize (obj);
}


/**
 * Simple abstraction for the wakelock mechanism found on every android device. In general
 * you never have to use this class as we don't work with wakelocks but in some situations
 * we can't work around them. Think twice before using this and ask other people if there
 * is a better solution!
 * NOTE: If there is no wakelock support build into your kernel (e.g. /sys/power/wake_*
 * nodes are not present) using this class does really nothing.
 */
GType fso_framework_wakelock_get_type (void) {
	static volatile gsize fso_framework_wakelock_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_wakelock_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkWakelockClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_wakelock_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkWakelock), 0, (GInstanceInitFunc) fso_framework_wakelock_instance_init, NULL };
		GType fso_framework_wakelock_type_id;
		fso_framework_wakelock_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoFrameworkWakelock", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_wakelock_type_id__volatile, fso_framework_wakelock_type_id);
	}
	return fso_framework_wakelock_type_id__volatile;
}


static void _vala_fso_framework_wakelock_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	FsoFrameworkWakelock * self;
	self = FSO_FRAMEWORK_WAKELOCK (object);
	switch (property_id) {
		case FSO_FRAMEWORK_WAKELOCK_NAME:
		g_value_set_string (value, fso_framework_wakelock_get_name (self));
		break;
		case FSO_FRAMEWORK_WAKELOCK_ACQUIRED:
		g_value_set_boolean (value, fso_framework_wakelock_get_acquired (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_fso_framework_wakelock_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	FsoFrameworkWakelock * self;
	self = FSO_FRAMEWORK_WAKELOCK (object);
	switch (property_id) {
		case FSO_FRAMEWORK_WAKELOCK_NAME:
		fso_framework_wakelock_set_name (self, g_value_get_string (value));
		break;
		case FSO_FRAMEWORK_WAKELOCK_ACQUIRED:
		fso_framework_wakelock_set_acquired (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



