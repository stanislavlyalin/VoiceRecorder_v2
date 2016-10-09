import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
  visible: true
  width: 500
  height: 500
  id: root

  Row {
    id: tools

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
