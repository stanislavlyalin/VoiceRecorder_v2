import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
  visible: true
  width: 300
  height: 500
  id: root

  ColumnLayout {
    anchors.fill: parent

    Text {
      id: qml_record_text
      objectName: "qml_record_text"
      Layout.fillHeight: true
      Layout.fillWidth: true
      font.pointSize: 20
      wrapMode: Text.WordWrap
      padding: 10
    }

    Text {
      id: qml_timer
      text: "00:00"
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      objectName: "qml_timer"
      Layout.maximumHeight: 100
      Layout.fillWidth: false
      font.pointSize: 20
    }

    RowLayout {
      id: tools
      height: 100
      Layout.fillHeight: true
      Layout.fillWidth: true
      spacing: 0
      anchors.bottom: parent.bottom
      anchors.right: parent.right
      anchors.left: parent.left
      anchors.margins: 0

      Button {
        id: start
        text: "Start"
        Layout.maximumHeight: 80
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        onClicked: {
          mouse.start()
        }
      }

      Button {
        id: stop
        text: "Stop"
        Layout.maximumHeight: 80
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
        onClicked: {
          mouse.stop();
        }
      }
    }
  }
}
