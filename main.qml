import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

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
      font.pointSize: 12
      wrapMode: Text.WordWrap
      padding: 10
    }

    Text {
      id: qml_timer
      objectName: "qml_timer"
      Layout.maximumHeight: 100
      Layout.fillWidth: true
      font.pointSize: 20
    }

    Row {
      id: tools
      Layout.maximumHeight: 100
      Layout.fillWidth: true

      Button {
        id: start
        text: "Start"
        onClicked: {
          mouse.start()
        }
      }

      Button {
        id: stop
        text: "Stop"
        onClicked: {
          mouse.stop();
        }
      }
    }
  }
}
