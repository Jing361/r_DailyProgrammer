#include<termios.h>
#include<unistd.h>

#include"hide_std_in.hh"

void hide_std_in::set_echo_hide( bool enable ){
  struct termios tty;

  tcgetattr( STDIN_FILENO, &tty );

  if( enable ){
    tty.c_lflag |= ECHO;
  } else {
    tty.c_lflag &= ~ECHO;
  }

  ( void ) tcsetattr( STDIN_FILENO, TCSANOW, &tty );
}

hide_std_in::hide_std_in(){
  set_echo_hide( true );
}

hide_std_in::~hide_std_in(){
  set_echo_hide( false );
}

