/*
 * Copyright (C) 2013 ~ 2018 National University of Defense Technology(NUDT) & Tianjin Kylin Ltd.
 *
 * Authors:
 *  Kobe Lee    xiangli@ubuntukylin.com/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QIcon>
#include <QDialog>
#include <QPointer>
#include <QAbstractButton>

class QAbstractButton;
class QButtonGroup;
class QLabel;
class QCloseEvent;
class QVBoxLayout;
class MyTristateButton;

#include <QBoxLayout>

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(const QString &title, const QString& message, QWidget *parent = 0);
    ~MyDialog();

    void updateSize();
    int buttonCount() const;
    QRect getParentGeometry() const;
    void moveToCenter();

signals:
    void buttonClicked(int index, const QString &text);

public slots:
    int addButton(const QString &text, bool isDefault = false);
    void setDefaultButton(QAbstractButton *button);
    void setTitle(const QString &title);
    void setMessage(const QString& message);
    int exec() Q_DECL_OVERRIDE;

public slots:
    void onButtonClicked();
    void onDefaultButtonTriggered();

protected:
    void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
    void hideEvent(QHideEvent *event) Q_DECL_OVERRIDE;
    void childEvent(QChildEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QLabel *m_messageLabel = nullptr;
    QLabel *m_titleLabel = nullptr;
    MyTristateButton *closeButton = nullptr;
//    QVBoxLayout *contentLayout = nullptr;
    QHBoxLayout *m_buttonLayout = nullptr;
    QHBoxLayout *m_topLayout = nullptr;
    QList<QAbstractButton*> buttonList;
    QList<QWidget*> contentList;

    QPointer<QAbstractButton> defaultButton;
    int clickedButtonIndex;

    QString m_title;
    QString m_message;

    QPoint dragPosition;
    bool mousePressed;
};

#endif // MYDIALOG_H
