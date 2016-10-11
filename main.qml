import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
  visible: true
  //width: 500
  //height: 500
  id: root

  Text {
    id: hint
    anchors.centerIn: parent
    height: parent.height
    width: parent.width
    font.pointSize: 36
    wrapMode: Text.WordWrap
    text: hint_text
  }

  Row {
    id: tools
    anchors.bottom: parent.bottom

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
