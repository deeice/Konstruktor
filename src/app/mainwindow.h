// Konstruktor - An interactive LDraw modeler for KDE
// Copyright (c)2006-2011 Park "segfault" J. K. <mastermind@planetmono.org>

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <string>

#include <QList>
#include <QMainWindow>
#include <QSet>
#include <QPair>
#include <QVector>

namespace ldraw 
{
  class model;
}

class QAction;
class QCloseEvent;
class QModelIndex;
class QTreeView;

namespace Konstruktor
{

class ActionManager;
class ContentsModel;
class ContentsView;
class Document;
class Editor;
class MenuManager;
class PartsWidget;
class RenderWidget;

class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
 public:
  MainWindow(QWidget *parent = 0L);
  ~MainWindow();
  
  unsigned int viewportModes() const;
  const Editor* editor() const { return editorGroup_; }
  
 signals:
  void activeModelChanged(ldraw::model *m);
  void viewChanged();
  void actionEnabled(bool enabled);
                    
 public slots:
  void modelModified(const QSet<int> &selection);
  void updateViewports();
  void changeCaption();
  void activate(bool b);
  void setStatusMessage(const QString &msg);
  
  void newFile();
  void openFile();
  void openFile(const QString &path);
  void closeFile();
  void saveFile();
  void saveFileAs();
  void quit();
  
  void newSubmodel();
  void deleteSubmodel();
  void modelProperties();
  
  void resetZoom();
  void resetDisplay();
  
  void render();
  
  void showConfigDialog();
                         
 private slots:
  void activeDocumentChanged(int index);
  void activeModelChanged(const std::string &name);
  void modelChanged(ldraw::model *m);
  void submodelViewDoubleClicked(const QModelIndex &index);
  void selectionChanged(const QSet<int> &cset);
  void gridModeChanged(QAction *action);
  void modelModified();
  void clipboardChanged();
  
  void notImplemented();
  void about();
  
 private:
  void closeEvent(QCloseEvent *event);
  
  void init();
  void initGui();
  void initActions();
  void initConnections();
  void initMenus();
  void initToolBars();
  bool confirmQuit();
  bool doSave(Document *document, bool newname = false);
  
 private:
  /*
   * Main window compositions
   */
  ActionManager *actionManager_;
  MenuManager *menuManager_;
  ContentsModel *contentsModel_;

  /*
   * Document management
   */
  Document *activeDocument_;
  QVector<QPair<QString, Document *> > documents_;
  QSet<QString> openedUrls_;
  Editor *editorGroup_;
  
  /*
   * Widgets
   */
  PartsWidget *partsWidget_;
  QTreeView *submodelList_;
  ContentsView *contentList_;	
  RenderWidget *renderWidget_[4];
  QTabBar *tabbar_;
  
  /*
   * State management
   */
  bool enabled_;
  int newcnt_;
};

}

#endif
