#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>

class VideoConverter : public QWidget {
    Q_OBJECT

public:
    VideoConverter();

private:
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QPushButton *inputButton;
    QPushButton *outputButton;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;
    QPushButton *convertButton;
//    QLabel *errorLabel;
//    QLabel *successLabel;
    QLabel *successErrorLabel;

    void connectSignalsAndSlots();
};
