import QtQuick 2.0
import QtQuick.Controls 2.12
import Qt.labs.folderlistmodel 1.0
import QtQuick.Window 2.15
import Qt.labs.qmlmodels 1.0
import Qt.labs.platform

import "Components/"

Item {

    // property string currFileName: ""
    // property int containerWidth: window.width * 0.35
    // property int containerHeight: window.width * 0.35
    property string currFileName: ""
    property int containerWidth: window.width * 0.4
    property int containerHeight: window.width * 0.4
    property int containerMargin: window.width * 0.05

    Window {
        id: advSearchWindow
        width: 600
        height: 500
        visible: false
        title: qsTr("Okno wyszukiwania zaawansowanego")

        Column {

            Text {
                height: advSearchWindow.height * 0.03
                width: advSearchWindow.width * 0.4
                horizontalAlignment: Text.AlignHCenter                   
            }


            Text {
                id: patientSearchText
                height: advSearchWindow.height * 0.07
                width: advSearchWindow.width 
                text: "Wyszukiwanie pacjenta"
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                
            }

            Row {
                Text {
                    id: patientIdText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "ID pacjenta"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: patientIdField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true
                    validator: IntValidator {bottom: 1; top: 9999999;} 
                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Row {
                Text {
                    id: patientPESELText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "PESEL"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: patientPESELField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true

                    validator: RegularExpressionValidator{
                        regularExpression: /^[0-9]{11}|99999999999/
                    }

                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Row {
                Text {
                    id: patientNameText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "Imię pacjenta"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: patientNameField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true

                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Row {
                Text {
                    id: patientSurnameText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "Nazwisko pacjenta"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: patientSurnameField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true

                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Row {
                Text {
                    id: patientAgeText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "Wiek pacjenta"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: patientAgeField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true
                    validator: RegularExpressionValidator{
                        regularExpression: /^[1-9][0-9]{1}|[1][0-9]{2}|199/
                    }
                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }



            Text {
                height: advSearchWindow.height * 0.03
                width: advSearchWindow.width * 0.4
                horizontalAlignment: Text.AlignHCenter                   
            }



            Text {
                id: studySearchText
                height: advSearchWindow.height * 0.07
                width: advSearchWindow.width 
                text: "Wyszukiwanie badania"
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                
                
            }

            Row {
                Text {
                    id: studyIdText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "ID badania"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: studyIdField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true
                    validator: IntValidator {bottom: 1; top: 9999999;} 

                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Row {
                Text {
                    id: studyTypeText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "Rodzaj badania"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                ComboBox {
                    model: ["CT", "MRI", "XR", "PET"]
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                }

                /* Inny rodzaj pola - zwykly textfield bez predefiniowanych/sugerowanych wartości
                TextField {       
                    id: studyTypeField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true

                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }*/
            }

            Row {
                Text {
                    id: studyDateText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "Data badania"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: studyDateField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse: true
                    inputMethodHints: Qt.ImhDate
                    onActiveFocusChanged: {
                        inputMask= "00-00-0000"
                    }
                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Row {
                Text {
                    id: studyNameText
                    height: advSearchWindow.height * 0.07
                    width: advSearchWindow.width * 0.4
                    text: "Nazwa badania"
                    horizontalAlignment: Text.AlignHCenter
                    
                }

                TextField {
                    id: studyNameField
                    height: advSearchWindow.height * 0.05
                    width: advSearchWindow.width * 0.4
                    horizontalAlignment: Text.AlignHCenter
                    selectByMouse : true

                    background: Rectangle {
                        radius: 2
                        color: "aliceblue"
                        border.color: "grey"
                        border.width: 0.5
                    }
                    
                }
            }

            Text {
                height: advSearchWindow.height * 0.07
                width: advSearchWindow.width * 0.4
                horizontalAlignment: Text.AlignHCenter                   
            }


            Button {
                id: confirmSearchBtn
                text: "Szukaj"
                height: advSearchWindow.height * 0.05
                width: advSearchWindow.width * 0.4
                onClicked: advSearchWindow.visible = false //ewentualnie mozna wyrzucic

                anchors {
                    horizontalCenter: patientSearchText.horizontalCenter
                }
            }

            
        }

    }
    
    Window {
        id: window
        width: 1200
        height: 800
        visible: true
        title: qsTr("Dicom Picture Viewer")


        TextField {
            id: searchBar
            height: containerHeight * 0.1
            cursorVisible: true
            selectByMouse : true
            placeholderText: "Wyszukiwanie pliku, np. case1.dcm"

            background: Rectangle {
                radius: 2
                border.color: "#333"
                border.width: 1
            }

            anchors {
                topMargin: containerHeight * 0.1
                top: parent.top
                right: advancedSearchBtn.left
                left: parent.left
                leftMargin: containerMargin 
                rightMargin: containerMargin * 0.25
            }

        }

        Button {
            id: advancedSearchBtn
            text: "Zaawansowane wyszukiwanie"
            width: window.width * 0.2
            height: searchBar.height
            onClicked: advSearchWindow.visible = true

            anchors {
                verticalCenter: searchBar.verticalCenter
                right: parent.right
                rightMargin: containerMargin
            }
        }

        FolderListModel {
            id: folderModel
            folder: StandardPaths.writableLocation(StandardPaths.AppDataLocation)
            nameFilters: [ searchBar.text + "*" ]
        }

        Text {
            id: picsListText
            width: scroll.width
            height: window.height * 0.05
            text: "Lista obrazów"
            font.bold: true
            horizontalAlignment: Text.AlignHCenter  
            font.pixelSize: 15


            anchors {
                top: searchBar.bottom
                topMargin: window.height * 0.05
                horizontalCenter: scroll.horizontalCenter

            }

        }

        ScrollView {
            id: scroll
            width: containerWidth
            height: containerHeight
            clip: true

            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                leftMargin: containerMargin
                top: picsListText.bottom
                right: img.left
                rightMargin: containerMargin * 0.5
            
            }

            TableView {
                property int selectedIndex
                id: tableView
                model: dicomTableModel
                anchors.fill: scroll
                delegate: TableItem {
                    id: delegate
                    height: 30
                    width: scroll / 3
                    label: model.display
                    selectedTableIndex: tableView.selectedIndex
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            tableView.selectedIndex = model.index;
                            currFileName = delegate.label
                        }
                    }
                }
            }
        }

        Image {
            id: img
            anchors {
                // right: imgDescrCol.left
                right: parent.right
                verticalCenter: parent.verticalCenter
                rightMargin: containerMargin * 0.5
            }
            width: containerWidth
            height: containerHeight
            source: "image://DicomImageProvider/" + currFileName
        }

        // Column {

        //     id: imgDescrCol
        //     width: containerWidth * 0.5
        //     spacing: 10

        //     Text {
        //         text: "ID Pacjenta: "
                
        //     }

        
        //     Text {
        //         text: "PESEL: "
                
        //     }

        //     Text {
        //         text: "Wiek: "
                
        //     }
        
        //     Text {
        //         text: "ID Badania: "
                
        //     }
      
        //     Text {
        //         text: "modalność: "
                
        //     }
        
        //     Text {
        //         text: "data badania: "
                
        //     }
        
        //     anchors {
        //         right: parent.right
        //         verticalCenter: parent.verticalCenter
        //         rightMargin: containerMargin
        //     }

        // }

        Button {
            id: loadDataBtn
            text: "Import danych"
            width: advancedSearchBtn.width 
            height: advancedSearchBtn.height
            anchors {
                bottom: parent.bottom
                bottomMargin: containerMargin
                horizontalCenter: parent.horizontalCenter
            }

        }
    }  
}
