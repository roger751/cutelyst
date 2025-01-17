/*
 * Copyright (C) 2013-2017 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef CUTELEE_VIEW_P_H
#define CUTELEE_VIEW_P_H

#include "cuteleeview.h"
#include "view_p.h"

#include <cutelee/engine.h>
#include <cutelee/templateloader.h>
#include <cutelee/cachingloaderdecorator.h>

namespace Cutelyst {

class CuteleeViewPrivate : public ViewPrivate
{
public:
    virtual ~CuteleeViewPrivate() override = default;

    QStringList includePaths;
    QString extension = QStringLiteral(".html");
    QString wrapper;
    QString cutelystVar;
    Cutelee::Engine *engine;
    QSharedPointer<Cutelee::FileSystemTemplateLoader> loader;
    QSharedPointer<Cutelee::CachingLoaderDecorator> cache;
    QHash<QLocale, QTranslator*> translators;
    QMultiHash<QString, QString> translationCatalogs;
};

}

#endif // CUTELEE_VIEW_P_H
