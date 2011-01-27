// Konstruktor - An interactive LDraw modeler for KDE
// Copyright (c)2006-2011 Park "segfault" J. K. <mastermind@planetmono.org>

#ifndef _PARTSWIDGET_H_
#define _PARTSWIDGET_H_

#include <QList>
#include <QMap>
#include <QWidget>

#include "partitems.h"

namespace Ui { class PartsWidget; }

class QListWidgetItem;
class QSortFilterProxyModel;
class QModelIndex;

namespace Konstruktor
{

class PartsModel;

class PartsWidget : public QWidget
{
	Q_OBJECT;

  public:
	PartsWidget(QWidget *parent = 0L);
	virtual ~PartsWidget();

  public slots:
	void initialize(const QString &search = QString(), bool hideUnofficial = false);
	void hideUnofficial(int checkState);

  private slots:
	void selectionChanged(const QModelIndex &current, const QModelIndex &previous);
	void iconSelected(QListWidgetItem *item);

  private:
	Ui::PartsWidget *ui_;
	PartsModel *model_;
	QSortFilterProxyModel *sortModel_;

	QString search_;
	bool hideUnofficial_;
	
	QList<PartCategory> categories_;
	QMap<int, PartCategory *> categorymap_;
	QMap<int, QList<PartItem> > list_;

	int lastCat_;
};

}


#endif

