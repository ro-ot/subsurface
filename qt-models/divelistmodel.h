#ifndef DIVELISTMODEL_H
#define DIVELISTMODEL_H

#include <QAbstractListModel>
#include "dive.h"

class Dive {
public:
	Dive(dive* d);

	QString date() const;
	void setDate(const QString &date);

	QString location() const;
	void setLocation(const QString &location);

	QString sac() const;
	void setSac(const QString &sac);

	QString gas() const;
	void setGas(const QString &gas);

	QString cylinder() const;
	void setCylinder(const QString &cylinder);

	QString suit() const;
	void setSuit(const QString &suit);

	QString weight() const;
	void setWeight(const QString &weight);

	QString temp() const;
	void setTemp(const QString &temp);

	QString duration() const;
	void setDuration(const QString &duration);

	QString depth() const;
	void setDepth(const QString &depth);

	QString rating() const;
	void setRating(const QString &rating);

	dive *thisDive() const;
	void setThisDive(dive *thisDive);

	QString diveNumber() const;
	void setDiveNumber(const QString &diveNumber);

	QString notes() const;
	void setNotes(const QString &notes);

	QString trip() const;
	void setTrip(const QString &trip);

private:
	QString m_diveNumber;
	QString m_trip;
	QString m_date;
	QString m_rating;
	QString m_depth;
	QString m_duration;
	QString m_temp;
	QString m_weight;
	QString m_suit;
	QString m_cylinder;
	QString m_gas;
	QString m_sac;
	QString m_location;
	QString m_notes;


	dive *m_thisDive;
};

class DiveListModel : public QAbstractListModel
{
	Q_OBJECT
public:

	enum DiveListRoles {
		DiveNumberRole = Qt::UserRole + 1,
		DiveTripRole,
		DiveDateRole,
		DiveRatingRole,
		DiveDepthRole,
		DiveDurationRole,
		DiveTemperatureRole,
		DiveWeightRole,
		DiveSuitRole,
		DiveCylinderRole,
		DiveGasRole,
		DiveSacRole,
		DiveLocationRole,
		DiveNotesRole
	};

	static DiveListModel *instance();
	DiveListModel(QObject *parent = 0);
	void addDive(dive *d);
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QHash<int, QByteArray> roleNames() const;

private:
	QList<Dive> m_dives;
	static DiveListModel *m_instance;
};

#endif // DIVELISTMODEL_H