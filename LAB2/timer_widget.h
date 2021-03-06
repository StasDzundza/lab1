#ifndef TIMER_WIDGET_H
#define TIMER_WIDGET_H

#include<QDialog>
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTimer>
#include<QTime>
#include<QCheckBox>
#include<QtMultimedia/QSound>

namespace Ui {
class timer_widget;
}

class timer_widget : public QDialog
{
    Q_OBJECT

public:
    explicit timer_widget(QWidget *parent = nullptr);
    ~timer_widget();
    int get_id();
private slots:
void OkClicked();
void on_hide_button_clicked();
void TextChanged(QString str);
void check_timer();
void turn_off_on();
void reset_clicked();
void replay_sound();
signals:
void current_time_signal(const QString&str,timer_widget*current_timer);
private:
    Ui::timer_widget *ui;
    static int index;
    int id;
    int timer_time_msec = 0;
    QVBoxLayout*layout;
    QVBoxLayout*main;

    QLabel*lbl;
    QLabel*time_left;
    QLineEdit*line;
    QPushButton*ok;
    QPushButton*start_stop;
    QPushButton*reset;
    QPushButton*hide;
    QCheckBox*do_not_distrub;
    QString alarm_time_text;
    QTimer*time_count;//the main timer which checking time

    QTime time_on_stopwatch;//time which is on the stopwatch
    QTime last_start;//time of last start stopwatch

    QTimer*time_player;//for sound
    QSound*alarm_sound;


};

#endif // TIMER_WIDGET_H
