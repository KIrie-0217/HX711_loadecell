#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include<iostream>

#include "server_C.h"

void server_C::init() {
	len = sizeof( struct sockaddr_in );
	// 受信バッファ初期化
	memset( buf, 0, sizeof( buf ) );
	// ソケット生成
	if( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) {
		perror( "socket" );
	}
}

void  server_C::set_port(int port_number){
	// 待ち受け用IP・ポート番号設定
	addr.sin_family = AF_INET;
	addr.sin_port = htons( port_number );

}

void server_C::set_host(std::string host_number){
	// ローカルホストを指定
	addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
	//addr.sin_addr.s_addr = INADDR_ANY;
}

void server_C::start(){
	// バインド
	if( bind( sockfd, (struct sockaddr *)&addr, sizeof( addr ) ) < 0 ) {
		perror( "bind" );
	}
	// 受信待ち
	if( listen( sockfd, SOMAXCONN ) < 0 ) {
		perror( "listen" );
	}
	// クライアントからのコネクト要求待ち
	if( ( client_sockfd = accept( sockfd, (struct sockaddr *)&from_addr, &len ) ) < 0 ) {
		perror( "accept" );
	}
	// main loop 
	while( 1 ) {
		flag =0;
		num = 0;

		rsize = recv( client_sockfd, buf, sizeof( buf ), 0 );
		
        if ( rsize > 0 ) {
			printf( "receive: %s\n", buf );
			
            /*
            for(int i = 0;i<rsize;i++){
				if(buf[i] == ','){
					flag = 0;
					try{
					outnum[num] = std::stod(out[num]);
					std::cout << "["<<num<<"]:"<< out[num] << std::endl;
					}
					catch(const std::invalid_argument&){
						std::cout << "invalid" << std::endl;
					}
					catch(const std::out_of_range&){
						std::cout << "oor" << std::endl;
					}

					num += 1;
				}

				if(buf[i] == '}'){
					flag = 0;
					try{
					outnum[num] = std::stod(out[num]);
					std::cout << "["<<num<<"]:"<< out[num] << std::endl;
					}
					catch(const std::invalid_argument& e){
						std::cout << "invalid" << std::endl;
					}
					catch(const std::out_of_range& e){
						std::cout << "oor" << std::endl;
					}

				}

				if (flag == 1 and buf[i] != '"'){
					out[num] += buf[i];
				}


				if(buf[i] == ':'){
					flag = 1;
				}



			}   */

		}  
        else if ( rsize == 0) {
		break;
		}


		// init of out
		for(int i =0;i<9;i++){
			out[i] = "";
			outnum[i] = 0;
		}

	}
 
	// ソケットクローズ
	close( client_sockfd );
	close( sockfd );
 
}
