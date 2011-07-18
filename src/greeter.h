/*
 * Copyright (C) 2010-2011 Robert Ancell.
 * Author: Robert Ancell <robert.ancell@canonical.com>
 * 
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

#ifndef _GREETER_H_
#define _GREETER_H_

#include "session.h"
#include "pam-session.h"

G_BEGIN_DECLS

#define GREETER_TYPE (greeter_get_type())
#define GREETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GREETER_TYPE, Greeter))

typedef struct GreeterPrivate GreeterPrivate;

typedef struct
{
    GObject         parent_instance;
    GreeterPrivate *priv;
} Greeter;

typedef struct
{
    GObjectClass parent_class;
    gboolean (*start_session)(Greeter *greeter, const gchar *session, gboolean is_guest);
} GreeterClass;

GType greeter_get_type (void);

Greeter *greeter_new (Session *session);

void greeter_set_selected_user (Greeter *greeter, const gchar *username, gint timeout);

void greeter_set_default_session (Greeter *greeter, const gchar *session);

const gchar *greeter_get_default_session (Greeter *greeter);

PAMSession *greeter_get_pam_session (Greeter *greeter);

gboolean greeter_start (Greeter *greeter);

void greeter_quit (Greeter *greeter);

G_END_DECLS

#endif /* _GREETER_H_ */
