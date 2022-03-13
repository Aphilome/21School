#ifndef REPLIES_H
#define REPLIES_H

#define MESSAGE					":<nick>!<user>@127.0.0.1 PRIVMSG <target> :<msg>\r\n"
#define SERVER_NAME				"anonimus"
#define RPL_WELCOME				":<server> 001 <nick> :Welcome to the Internet Relay Network <nick>!<user>@<host>\r\n"
#define RPL_AWAY					":<server> 301 <nick> :<away message>\r\n"
#define RPL_MOTD_1				":<server> 372 * :-                .-'\"\"\"''---.___\r\n"
#define RPL_MOTD_2				":<server> 372 * :-              .'               \"'-.___\r\n"
#define RPL_MOTD_3				":<server> 372 * :-            _'              _'-\"'\"\"\"  \"\"\"-\r\n"
#define RPL_MOTD_4				":<server> 372 * :-           /    7        .'\"              \"->\r\n"
#define RPL_MOTD_5				":<server> 372 * :-          .    .|     _-'                   '.\r\n"
#define RPL_MOTD_6				":<server> 372 * :-         .  .'\"  :   '.         _.------._  ''\r\n"
#define RPL_MOTD_7				":<server> 372 * :-        .  -      . .'       .-'  \"-   .' \\ :\r\n"
#define RPL_MOTD_8				":<server> 372 * :-        | '        >       .'.''\"\\\"-   .'\\\"_'\r\n"
#define RPL_MOTD_9				":<server> 372 * :-        |'        <      .'   :__/  : :_.':'\r\n"
#define RPL_MOTD_10				":<server> 372 * :     .--'-._      :   .--:     -._.'  '._.'\r\n"
#define RPL_MOTD_11				":<server> 372 * :    '>      '.     '. | '              .' :\r\n"
#define RPL_MOTD_12				":<server> 372 * :   '.        :'     '-'.____        .__.  '\r\n"
#define RPL_MOTD_13				":<server> 372 * :    /         :             :.          .'\r\n"
#define RPL_MOTD_14				":<server> 372 * :    \\.       /              | '\"-_  __-'\r\n"
#define RPL_MOTD_15				":<server> 372 * :      \\.'-'\"'         .'\"\":''    :-\"\"\"\"'.\r\n"
#define RPL_MOTD_16				":<server> 372 * :                     :   :               .\r\n"
#define RPL_MOTD_17				":<server> 372 * :                     |  :                :\r\n"
#define RPL_MOTD_18				":<server> 372 * :                     | :           .''.  :\r\n"
#define RPL_MOTD_19				":<server> 372 * :                     |.'.        _.:   '.:\r\n"
#define RPL_MOTD_20				":<server> 372 * :                     |    '---'\"\"  :    :\"\r\n"
#define RPL_MOTD_21				":<server> 372 * :                     |     '      :     :\r\n"
#define RPL_MOTD_22				":<server> 372 * :                     .'.___:._   .'    .\r\n"
#define RPL_MOTD_23				":<server> 372 * :                      .  '    '\"'.     '\r\n"
#define RPL_MOTD_24				":<server> 372 * :                      |   :      '    :\r\n"
#define RPL_MOTD_25				":<server> 372 * :                      :    .    :    ' :\r\n"
#define RPL_MOTD_26				":<server> 372 * :        _.-'\"'--..__   :   : . :    .  _:\r\n"
#define RPL_MOTD_27				":<server> 372 * :     .'      .       \"-:   :   '   ..-\"  :\r\n"
#define RPL_MOTD_28				":<server> 372 * :    (         '-       :   :._:   /   _.--\"\"\"--._\r\n"
#define RPL_MOTD_29				":<server> 372 * :     '          '. _....:  : .   / .-'           '.\r\n"
#define RPL_MOTD_30				":<server> 372 * :      '           :  .\"\" \"\"'-'  /-\"               )\r\n"
#define RPL_MOTD_31				":<server> 372 * :       '._        :  :     ..-'                  /\r\n"
#define RPL_MOTD_32				":<server> 372 * :          '-._     \\'' _ .'\"\"\"\"\"\"'-.         _.-\r\n"
#define RPL_MOTD_33				":<server> 372 * :             .'--.__ .' '           - ____.-'\r\n"
#define RPL_MOTD_34				":<server> 372 * :            :         \"\":-.._______.'\r\n"
#define RPL_MOTD_35				":<server> 372 * :             '-.....-'''\r\n"
#define RPL_MOTDSTART			":<server> 375 <nick> :MOTD start\r\n"
#define RPL_ENDOFMOTD			":<server> 376 <nick> :MOTD end\r\n"
#define ERR_NOSUCHNICK			":<server> 401 <nick> :No such nick/channel\r\n"
#define ERR_NORECIPIENT			":<server> 411 <nick> :No recipient given\r\n"
#define ERR_NOTEXTTOSEND			":<server> 412 <nick> :No text to send\r\n"
#define ERR_NONICKNAMEGIVEN		":<server> 431 <nick> :No nickname given\r\n"
#define ERR_ERRONEUSNICKNAME		":<server> 432 :Erroneous nickname\r\n"
#define ERR_NICKNAMEINUSE		":<server> 433 <nick> :Nickname is already in use\r\n"
#define ERR_UNAVAILRESOURCE		":<server> 437 <nick> Nick/channel is temporarily unavailable\r\n"
#define ERR_NEEDMOREPARAMS		":<server> 461 <nick> :Not enough parameters\r\n"
#define ERR_ALREADYREGISTRED		":<server> 462 <nick> :Unauthorized command (already registered)\r\n"
#define ERR_PASSWDMISMATCH		":<server> 464 <nick> :Password incorrect\r\n"



#define RPL_MOTD_X				":<server> 372 * :\
                .-'\"\"\"''---.___\n\
              .'               \"'-.___\n\
            _'              _'-\"'\"\"\"  \"\"\"-\n\
            /    7        .'\"              \"->\n\
          .    .|     _-'                   '.\n\
         .  .'\"  :   '.         _.------._  ''\n\
        .  -      . .'       .-'  \"-   .' \\ :\n\
        | '        >       .'.''\"\\\"-   .'\\\"_'\n\
        |'        <      .'   :__/  : :_.':'\n\
     .--'-._      :   .--:     -._.'  '._.'\n\
    '>      '.     '. | '              .' :\n\
   '.        :'     '-'.____        .__.  '\n\
    /         :             :.          .'\n\
    \\.       /              | '\"-_  __-'\n\
      \\.'-'\"'         .'\"\":''    :-\"\"\"\"'.\n\
                     :   :               .\n\
                     |  :                :\n\
                     | :           .''.  :\n\
                     |.'.        _.:   '.:\n\
                     |    '---'\"\"  :    :\"\n\
                     |     '      :     :\n\
                     .'.___:._   .'    .\n\
                      .  '    '\"'.     '\n\
                      |   :      '    :\n\
                      :    .    :    ' :\n\
        _.-'\"'--..__   :   : . :    .  _:\n\
     .'      .       \"-:   :   '   ..-\"  :\n\
    (         '-       :   :._:   /   _.--\"\"\"--._\n\
     '          '. _....:  : .   / .-'           '.\n\
      '           :  .\"\" \"\"'-'  /-\"               )\n\
       '._        :  :     ..-'                  /\n\
          '-._     \\'' _ .'\"\"\"\"\"\"'-.         _.-\n\
             .'--.__ .' '           - ____.-'\n\
            :         \"\":-.._______.'\n\
             '-.....-'''\r\n"

#endif
