/*
 * Copyright (C) 2017 ~ 2017 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <DWindowManagerHelper>

#include "eventmonitor.h"

DWIDGET_USE_NAMESPACE

class QLineEdit;
class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void onWindowListChanged();
    void onInputFinished();
    void onGetCurrentFocusWindow();

private:
    QUdpSocket *m_socket;
    DWindowManagerHelper *m_wmHelper;
    EventMonitor *m_monitor;
    DForeignWindow *m_mcWindow;
    QLineEdit *m_lineEdit;
    bool m_isActive;
};

#endif // WIDGET_H
