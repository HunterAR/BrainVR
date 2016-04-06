#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pugixml-1.7/src/pugixml.hpp"
#include <QFileDialog>
#include<QDialog>
#include <qdir.h>
#include <iostream>
#include <QString>
#include <QVector>
#include "SVRPredictor.h"

using namespace MachineLearningPrediction;
using namespace std;
QString pathname = "hey";
QVector <QString> txtValue;
QVector <QString> studyTxtValue;
QVector<QString> storeNode;
QVector<QString> storeStudyNode;
QVector<QString> userNode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("Study Tracker");
    this->setStyleSheet("background-color: white;");
    ui->Import->setStyleSheet("background-color: rgb(53,123,193); color: white");
    ui->Export->setStyleSheet("background-color: rgb(53,123,193); color: white");
    ui->StudExport->setStyleSheet("background-color: rgb(53,123,193); color: white");
    ui->StudImport->setStyleSheet("background-color: rgb(53,123,193); color: white");
    ui->AssessLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->CasOrLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->CurNoUsersLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->DateLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->ExpLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->NoCasLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->NoUsersLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->SALab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->ScoresLab_1->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->ScoresLab_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->SIDLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->SpecCasesLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->TimeLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->UIDLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->CalculateScore->setStyleSheet("background-color: green; color: white");
    ui->DiffClass_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->ImageType_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->MachLearn_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->MeshMeas_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->NTRegTrans_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->PatientInfo_2->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->StudyName->setStyleSheet("background-color:white; color: green");
    ui->tabWidget->setStyleSheet("background-color: white");
    ui->scoreLab->setStyleSheet("background-color: white; color: rgb(65,64,64)");
    ui->UIDLab_2->setStyleSheet("background-color: white; color: green");
    ui->StudyName_2->setStyleSheet("background-color: white; color: green");
    ui->StudyName_3->setStyleSheet("background-color: white; color: green");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void parseCase (QString path) {

        storeNode.clear();
        QByteArray bite = path.toLatin1();
        const char *load_path = bite.data();
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(load_path);
        cout << "Load result: " << result.description() << ", Case #: " << doc.child("case").attribute("caseid").value() << endl;

        for (pugi::xml_node node = doc.child("case").first_child(); node; node = node.next_sibling()) {

            cout << node.name() << ": " << node.child_value() << endl;
            storeNode.append(node.child_value());

            for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it){
                cout << it->name() << " " << it->child_value() <<endl;
                storeNode.append(it->child_value());
            }
        }
        cout << endl;
}

void parseStudy (QString val) {

    storeStudyNode.clear();
    QByteArray bite = val.toLatin1();
    const char *load_path = bite.data();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(load_path);
    cout << "Load result: " << result.description() << ", Study #: " << doc.child("study").attribute("userid").value() << endl;

    for (pugi::xml_node node = doc.child("study").first_child(); node; node = node.next_sibling()) {

        cout << node.name() << ": " << node.child_value() << endl;
        storeStudyNode.append(node.child_value());

        for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it){
            cout << it->name() << " " << it->child_value() <<endl;
            storeStudyNode.append(it->child_value());

        }
    }
    cout << endl;
}

//void parseUser (QString pth) {

//    userNode.clear();
//    QByteArray bite = pth.toLatin1();
//    const char *load_path = bite.data();
//    pugi::xml_document doc;
//    pugi::xml_parse_result result = doc.load_file(load_path);
//    cout << "Load result: " << result.description() << ", User #: " << doc.child("user").attribute("userid").value() << endl;

//    for (pugi::xml_node node = doc.child("user").first_child(); node; node = node.next_sibling()) {

//        cout << node.name() << ": " << node.child_value() << endl;
//        userNode.append(node.child_value());

//        for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it){
//            cout << it->name() << " " << it->child_value() <<endl;
//            userNode.append(it->child_value());
//        }
//    }
//    cout << endl;
//}

void MainWindow::on_actionImport_triggered()
{
    storeNode.clear();
    QString filename = QFileDialog::getOpenFileName(
               this,
               tr("Open File"),
               "/Users/nimibassi/DesignProject",
               "All files (*.*);; XML file (*.xml)"
               );
    QDir d = QFileInfo(filename).absolutePath();
    pathname = d.absoluteFilePath("XMLExample_case.xml");

    parseCase(pathname.toUtf8());

    for(int i = 0; i<storeNode.count(); i++){
        cout << i <<" " <<storeNode.value(i).toStdString() <<endl;
    }

    ui->IT_2->setText(storeNode.value(0));
    ui->PI_2->setText(storeNode.value(2));
    ui->NT_2->setText(storeNode.value(8));
    ui->TVV_2->setText(storeNode.value(14));
    ui->ER_2->setText(storeNode.value(15));
    ui->MS_2->setText(storeNode.value(16));
    ui->AHV_2->setText(storeNode.value(17));
    ui->Eccentricity->setText(storeNode.value(18));
    ui->EllVolume->setText(storeNode.value(19));
    ui->DisEntry->setText(storeNode.value(20));
    ui->DC_2->setText(storeNode.value(21));
    ui->ED_2->setText(storeNode.value(24));
    ui->PSP_2->setText(storeNode.value(25));
}

void MainWindow::on_Import_clicked()
{
    storeNode.clear();
    QString filename = QFileDialog::getOpenFileName(
               this,
               tr("Open File"),
               "/Users/nimibassi/DesignProject",
               "All files (*.*);; XML file (*.xml)"
               );
    QDir d = QFileInfo(filename).absolutePath();
    pathname = d.absoluteFilePath("XMLExample_case.xml");

    parseCase(pathname.toUtf8());

    for(int i = 0; i<storeNode.count(); i++){
        cout << i <<" " <<storeNode.value(i).toStdString() <<endl;
    }

    ui->IT_2->setText(storeNode.value(0));
    ui->PI_2->setText(storeNode.value(2));
    ui->NT_2->setText(storeNode.value(8));
    ui->TVV_2->setText(storeNode.value(14));
    ui->ER_2->setText(storeNode.value(15));
    ui->MS_2->setText(storeNode.value(16));
    ui->AHV_2->setText(storeNode.value(17));
    ui->Eccentricity->setText(storeNode.value(18));
    ui->EllVolume->setText(storeNode.value(19));
    ui->DisEntry->setText(storeNode.value(20));
    ui->DC_2->setText(storeNode.value(21));
    ui->ED_2->setText(storeNode.value(24));
    ui->PSP_2->setText(storeNode.value(25));
}

void MainWindow::on_StudImport_clicked()
{
    storeStudyNode.clear();
    QString filename = QFileDialog::getOpenFileName(
               this,
               tr("Open File"),
               "/Users/nimibassi/DesignProject",
               "All files (*.*);; XML file (*.xml)"
               );
    QDir d = QFileInfo(filename).absolutePath();
    pathname = d.absoluteFilePath("XMLExample_study.xml");

    parseStudy(pathname.toUtf8());

    for(int i = 0; i<storeStudyNode.count(); i++){
        cout << i <<" " <<storeStudyNode.value(i).toStdString() <<endl;
    }

    ui->StudyName->setText(storeStudyNode.value(0));
    ui->StudyID->setText(storeStudyNode.value(2));
    ui->StartDate->setText(storeStudyNode.value(4));
    ui->ExpNoUsers->setText(storeStudyNode.value(6));
    ui->CurNoUsers->setText(storeStudyNode.value(8));
    ui->NoCas->setText(storeStudyNode.value(10));
    ui->COlist->addItem(storeStudyNode.value(12));
    ui->COlist->addItem(storeStudyNode.value(14));
    ui->COlist->addItem(storeStudyNode.value(16));
    ui->COlist->addItem(storeStudyNode.value(18));
    ui->SAList->addItem(storeStudyNode.value(20));
    ui->SAList->addItem(storeStudyNode.value(22));
    ui->UIDLab_3->setText("1");
    ui->UIDLab_4->setText("2");
    ui->UIDLab_5->setText("22, 18, 17, 32, 45");
    ui->UIDLab_6->setText("12.12, -0.0087, 0.676; 12.12, -0.0087, 0.676; 12.12, -0.0087, 0.676; 12.12, -0.0087, 0.676; 0.98, 0.001, -2.12");
    ui->UIDLab_7->setText("12.12, -0.0087, 0.676; 12.12, -0.0087, 0.676; 12.12, -0.0087, 0.676; 12.12, -0.0087, 0.676; 0.98, 0.001, -2.12");
    ui->UIDLab_8->setText("7/10");
    ui->UIDLab_9->setText("4/10");
}

//void MainWindow::on_addUser_clicked()
//{
//    userNode.clear();
//    QString filename = QFileDialog::getOpenFileName(
//               this,
//               tr("Open File"),
//               "/Users/nimibassi/DesignProject",
//               "All files (*.*);; XML file (*.xml)"
//               );
//    QDir d = QFileInfo(filename).absolutePath();
//    pathname = d.absoluteFilePath("XMLExample_user.xml");

//    parseUser(pathname.toUtf8());

//    for(int i = 0; i<userNode.count(); i++){
//        cout << i <<" " <<userNode.value(i).toStdString() <<endl;
//    }

//}

void MainWindow::on_actionExport_triggered()
{
        txtValue.insert(0, ui->IT_2->text());
        txtValue.insert(1, ui->PI_2->toPlainText());
        txtValue.insert(2, ui->NT_2->text());
        txtValue.insert(3, ui->TVV_2->text());
        txtValue.insert(4, ui->ER_2->text());
        txtValue.insert(5, ui->MS_2->text());
        txtValue.insert(6, ui->AHV_2->text());
        txtValue.insert(7, ui->Eccentricity->text());
        txtValue.insert(8, ui->EllVolume->text());
        txtValue.insert(9, ui->DisEntry->text());
        txtValue.insert(10, ui->DC_2->text());
        txtValue.insert(11, ui->ED_2->text());
        txtValue.insert(12, ui->PSP_2->text());

        for (int i = 0; i<txtValue.count(); i++) {
            cout<< i << " " << txtValue.value(i).toStdString() << endl;
        }

        // Generate new XML document within memory
            pugi::xml_document doc;

            // Generate XML declaration
            auto declarationNode = doc.append_child(pugi::node_declaration);
            declarationNode.append_attribute("version")    = "1.0";
            declarationNode.append_attribute("encoding")   = "UTF-8";
            declarationNode.append_attribute("standalone") = "yes";
            // A valid XML doc must contain a single root node of any name
            pugi::xml_node root = doc.append_child("case");
            pugi::xml_node IT_node = root.append_child("imagetype");
            IT_node.append_child(pugi::node_pcdata).set_value(txtValue.value(0).toLatin1());
            pugi::xml_node PI_node = root.append_child("patientinfo");
            PI_node.append_child(pugi::node_pcdata).set_value(txtValue.value(1).toLatin1());
            pugi::xml_node NT_node = root.append_child("NTregistrationtransform");
            NT_node.append_child(pugi::node_pcdata).set_value(txtValue.value(2).toLatin1());
            pugi::xml_node M_node = root.append_child("Measures");
            pugi::xml_node V_node = M_node.append_child("totalventricularvolume");
            V_node.append_child(pugi::node_pcdata).set_value(txtValue.value(3).toLatin1());
            pugi::xml_node E_node = M_node.append_child("evansratio");
            E_node.append_child(pugi::node_pcdata).set_value(txtValue.value(4).toLatin1());
            pugi::xml_node Mi_node = M_node.append_child("midlineshift");
            Mi_node.append_child(pugi::node_pcdata).set_value(txtValue.value(5).toLatin1());
            pugi::xml_node Ah_node = M_node.append_child("anteriorhornvolume");
            Ah_node.append_child(pugi::node_pcdata).set_value(txtValue.value(6).toLatin1());
            pugi::xml_node Ecc_node = M_node.append_child("eccentricity");
            Ecc_node.append_child(pugi::node_pcdata).set_value(txtValue.value(7).toLatin1());
            pugi::xml_node EV_node = M_node.append_child("ellipsoidvolume");
            EV_node.append_child(pugi::node_pcdata).set_value(txtValue.value(8).toLatin1());
            pugi::xml_node DfE_node = M_node.append_child("distancefromentry");
            DfE_node.append_child(pugi::node_pcdata).set_value(txtValue.value(9).toLatin1());
            pugi::xml_node DC_node = root.append_child("difficultyclassification");
            DC_node.append_child(pugi::node_pcdata).set_value(txtValue.value(10).toLatin1());
            pugi::xml_node ML_node = root.append_child("machinelearning");
            pugi::xml_node ED_node = ML_node.append_child("estimateddifficulty");
            ED_node.append_child(pugi::node_pcdata).set_value(txtValue.value(11).toLatin1());
            pugi::xml_node PSP_node = ML_node.append_child("probabilityofsinglepass");
            PSP_node.append_child(pugi::node_pcdata).set_value(txtValue.value(12).toLatin1());
            // Save XML tree to file.
            // default indentation is tab character.
           bool saveSucceeded = doc.save_file("C:/Users/Ishan/Documents/data-processed/newCase.xml", PUGIXML_TEXT("  "));
           cout << saveSucceeded << "File saved." << endl;
}

void MainWindow::on_Export_clicked()
{
    txtValue.insert(0, ui->IT_2->text());
    txtValue.insert(1, ui->PI_2->toPlainText());
    txtValue.insert(2, ui->NT_2->text());
    txtValue.insert(3, ui->TVV_2->text());
    txtValue.insert(4, ui->ER_2->text());
    txtValue.insert(5, ui->MS_2->text());
    txtValue.insert(6, ui->AHV_2->text());
    txtValue.insert(7, ui->Eccentricity->text());
    txtValue.insert(8, ui->EllVolume->text());
    txtValue.insert(9, ui->DisEntry->text());
    txtValue.insert(10, ui->DC_2->text());
    txtValue.insert(11, ui->ED_2->text());
    txtValue.insert(12, ui->PSP_2->text());

    for (int i = 0; i<txtValue.count(); i++) {
        cout<< i << " " << txtValue.value(i).toStdString() << endl;
    }

    // Generate new XML document within memory
        pugi::xml_document doc;

        // Generate XML declaration
        auto declarationNode = doc.append_child(pugi::node_declaration);
        declarationNode.append_attribute("version")    = "1.0";
        declarationNode.append_attribute("encoding")   = "UTF-8";
        declarationNode.append_attribute("standalone") = "yes";
        // A valid XML doc must contain a single root node of any name
        pugi::xml_node root = doc.append_child("case");
        pugi::xml_node IT_node = root.append_child("imagetype");
        IT_node.append_child(pugi::node_pcdata).set_value(txtValue.value(0).toLatin1());
        pugi::xml_node PI_node = root.append_child("patientinfo");
        PI_node.append_child(pugi::node_pcdata).set_value(txtValue.value(1).toLatin1());
        pugi::xml_node NT_node = root.append_child("NTregistrationtransform");
        NT_node.append_child(pugi::node_pcdata).set_value(txtValue.value(2).toLatin1());
        pugi::xml_node M_node = root.append_child("Measures");
        pugi::xml_node V_node = M_node.append_child("totalventricularvolume");
        V_node.append_child(pugi::node_pcdata).set_value(txtValue.value(3).toLatin1());
        pugi::xml_node E_node = M_node.append_child("evansratio");
        E_node.append_child(pugi::node_pcdata).set_value(txtValue.value(4).toLatin1());
        pugi::xml_node Mi_node = M_node.append_child("midlineshift");
        Mi_node.append_child(pugi::node_pcdata).set_value(txtValue.value(5).toLatin1());
        pugi::xml_node Ah_node = M_node.append_child("anteriorhornvolume");
        Ah_node.append_child(pugi::node_pcdata).set_value(txtValue.value(6).toLatin1());
        pugi::xml_node Ecc_node = M_node.append_child("eccentricity");
        Ecc_node.append_child(pugi::node_pcdata).set_value(txtValue.value(7).toLatin1());
        pugi::xml_node EV_node = M_node.append_child("ellipsoidvolume");
        EV_node.append_child(pugi::node_pcdata).set_value(txtValue.value(8).toLatin1());
        pugi::xml_node DfE_node = M_node.append_child("distancefromentry");
        DfE_node.append_child(pugi::node_pcdata).set_value(txtValue.value(9).toLatin1());
        pugi::xml_node DC_node = root.append_child("difficultyclassification");
        DC_node.append_child(pugi::node_pcdata).set_value(txtValue.value(10).toLatin1());
        pugi::xml_node ML_node = root.append_child("machinelearning");
        pugi::xml_node ED_node = ML_node.append_child("estimateddifficulty");
        ED_node.append_child(pugi::node_pcdata).set_value(txtValue.value(11).toLatin1());
        pugi::xml_node PSP_node = ML_node.append_child("probabilityofsinglepass");
        PSP_node.append_child(pugi::node_pcdata).set_value(txtValue.value(12).toLatin1());
        // Save XML tree to file.
        // default indentation is tab character.
       bool saveSucceeded = doc.save_file("/Users/sabrinaren/Desktop/capstone/final pres/data-processed/newCase.xml", PUGIXML_TEXT("  "));
       cout << saveSucceeded << "File saved." << endl;
}

void MainWindow::on_StudExport_clicked()
{
    studyTxtValue.insert(0, ui->StudyName->text());
    studyTxtValue.insert(1, ui->StudyID->text());
    studyTxtValue.insert(2, ui->StartDate->text());
    studyTxtValue.insert(3, ui->ExpNoUsers->text());
    studyTxtValue.insert(4, ui->CurNoUsers->text());
    studyTxtValue.insert(5, ui->NoCas->text());
    studyTxtValue.insert(6, ui->COlist->item(0)->text());
    studyTxtValue.insert(7, ui->COlist->item(1)->text());
    studyTxtValue.insert(8, ui->COlist->item(2)->text());
    studyTxtValue.insert(9, ui->COlist->item(3)->text());
    studyTxtValue.insert(10, ui->SAList->item(0)->text());
    studyTxtValue.insert(11, ui->SAList->item(1)->text());

    for (int i = 0; i<studyTxtValue.count(); i++) {
        cout<< i << " " << studyTxtValue.value(i).toStdString() << endl;
    }

    // Generate new XML document within memory
        pugi::xml_document doc;

        // Generate XML declaration
        auto declarationNode = doc.append_child(pugi::node_declaration);
        declarationNode.append_attribute("version")    = "1.0";
        declarationNode.append_attribute("encoding")   = "UTF-8";
        declarationNode.append_attribute("standalone") = "yes";
        // A valid XML doc must contain a single root node of any name
        pugi::xml_node root = doc.append_child("study");
        pugi::xml_node SN_node = root.append_child("studyname");
        SN_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(0).toLatin1());
        pugi::xml_node SID_node = root.append_child("studyid");
        SID_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(1).toLatin1());
        pugi::xml_node SD_node = root.append_child("startdate");
        SD_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(2).toLatin1());
        pugi::xml_node E_node = root.append_child("expectednumberofusers");
        E_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(3).toLatin1());
        pugi::xml_node C_node = root.append_child("currentnumberofusers");
        C_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(4).toLatin1());
        pugi::xml_node No_node = root.append_child("numberofcases");
        No_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(5).toLatin1());
        pugi::xml_node SBO_node = root.append_child("SBcaseorder");
        SBO_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(6).toLatin1());
        pugi::xml_node SBO2_node = root.append_child("SB2caseorder");
        SBO2_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(7).toLatin1());
        pugi::xml_node ARO_node = root.append_child("ARcaseorder");
        ARO_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(8).toLatin1());
        pugi::xml_node AR2_node = root.append_child("AR2caseorder");
        AR2_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(9).toLatin1());
        pugi::xml_node SA_node = root.append_child("studyarrangement");
        SA_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(10).toLatin1());
        pugi::xml_node SA2_node = root.append_child("studyarrangement");
        SA2_node.append_child(pugi::node_pcdata).set_value(studyTxtValue.value(11).toLatin1());

        // Save XML tree to file.
        // default indentation is tab character.
       bool saveSucceeded = doc.save_file("/Users/sabrinaren/Desktop/capstone/final pres/data-processed/newStudy.xml", PUGIXML_TEXT("  "));
       cout << saveSucceeded << "File saved." << endl;
}

void MainWindow::on_CalculateScore_clicked()
{
    SVRPredictor svr;
    svr.setDataFolder("/Users/sabrinaren/Desktop/capstone/final pres/data");
    sample_type m;
    m(0, 0) = ui->Eccentricity->text().toDouble();
    m(1, 0) = ui->EllVolume->text().toDouble();
    m(2, 0) = ui->DisEntry->text().toDouble();
    int pct_diff = svr.getPercentageDifference(m) * 100;

    QString output;
    if (pct_diff >= 0){
        output = QString("Percentage Reduction in Difficulty with AR:\n %1 %").arg(pct_diff);
    }
    else{
        output = QString("Percentage Increase in Difficulty with AR:\n %1 %").arg(pct_diff);
    }
    //call calculate score function
    ui->scoreLab->setText(output);
}


