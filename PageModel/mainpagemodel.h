#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include <QObject>
#include <memory>

class SettingsRepository;

class MainPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool saveDirectorySet READ isSaveDirectorySet)
public:
    explicit MainPageModel(QObject *parent = 0);
    ~MainPageModel();

    bool isSaveDirectorySet();

public slots:
    void onSaveDirectoryChange(const QString& path);

private:
    std::shared_ptr<SettingsRepository> _settingsRepo;
};

#endif // MAINPAGEMODEL_H
