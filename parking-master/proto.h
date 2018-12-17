#ifndef PROTO_H
#define PROTO_H

#include<stdint.h>
#pragma pack(1)
#define SERVER_DEFAULT_IP	"192.168.191.4"
#define SIZE				64


//登录协议
#define LOGIN_SERVER_IP         SERVER_DEFAULT_IP
#define LOGIN_SERVER_PORT    	2222
#define LOGIN_STATUS_OK			0
#define LOGIN_STATUS_FAILC		1
#define LOGIN_STATUS_FAILP		2

struct login_st{
    char username[SIZE];
    char passwd[SIZE];
    int8_t state;
};

//注册协议
#define RGS_SERVER_IP			SERVER_DEFAULT_IP
#define RGS_SERVER_PORT			1111
#define RGS_SERVER_OK			0
#define RGS_SERVER_FAIL 		1

struct rgs_st{
    char username[SIZE];
    char passwd[SIZE];
    int8_t state;
};
//添加创建好友协议
#define ADD_SERVER_IP           SERVER_DEFAULT_IP
#define ADD_SERVER_PORT         4444
#define ADD_SERVER_OK           0
#define ADD_SERVER_FAIL         1
struct add_st{
    char username[SIZE];
    char mename[SIZE];
    int8_t state;
};
//设置密保协议
#define MI_SERVER_IP            SERVER_DEFAULT_IP
#define MI_SERVER_PORT          3333
#define MI_SERVER_OK            0
#define MI_SERVER_FAIL          1

struct mi_st{
    char question[SIZE];
    char answer[SIZE];
    int8_t state;
};
#endif // PROTO_H
