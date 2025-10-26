int register_selected = 0;
// 0 none 1 username 2 password
char register_user[30];
char register_password[30];
char register_cover[30];
buttons *manager_register;

void register_click() {
    register_selected = 0;
    if (mouse.x > 335 && mouse.x < 671 && mouse.y > 320 && mouse.y < 352) {
        register_selected = 1;
    }
    if (mouse.x > 335 && mouse.x < 671 && mouse.y > 412 && mouse.y < 445) {
        register_selected = 2;
    }
    tick_click(manager_register);
}

void register_register_click() {
    strcpy(tmp, "data\\");
    strcat(tmp, register_user);
    fp = fopen(tmp, "rb");
    if (fp != NULL) {
        fclose(fp);
        Text(380, 660, "注册失败，用户名被占用！", PINK);
    } else {
        fp = fopen(tmp, "wb");
        fputs(register_password, fp);
        fclose(fp);
        hello_msg = "注册成功，请登录！";
        paint(1);
    }
}

void register_back_click() {
    hello_msg = "";
    paint(1);
}

void register_key(int i) {
    int len, j;
    if (register_selected == 1) {
        len = strlen(register_user);
        if (i == 8) {
            if (len > 0) {
                register_user[len - 1] = '\0';
            }
        } else {
            if (len < 19) {
                register_user[len] = i;
                register_user[len + 1] = '\0';
            }
        }
        Bar(336, 321, 672, 351, WHITE);
        EngText(337, 324, register_user, BLACK);
    }
    if (register_selected == 2) {
        len = strlen(register_password);
        if (i == 8) {
            if (len > 0) {
                register_password[len - 1] = '\0';
            }
        } else {
            if (len < 19) {
                register_password[len] = i;
                register_password[len + 1] = '\0';
            }
        }
        len = strlen(register_password);
        Bar(336, 413, 609, 444, WHITE);
        for (j = 0; j < 30; j++) {
            register_cover[j] = '*';
        }
        register_cover[len] = '\0';
        EngText(337, 416, register_cover, BLACK);
    }
}

void register_move() {
    tick_move(manager_register);
}

void draw_register() {
    button *btn;
    Picture(0, 0, "zc.bmp");
    register_user[0] = '\0';
    register_password[0] = '\0';

    btn = new_button(302, 545, 504, 596, "注册", IvoryWhite, DARK_GREY, LIGHT_GREY, register_register_click);
    manager_register = push(btn, NULL);
    btn = new_button(602, 545, 804, 596, "返回", IvoryWhite, DARK_GREY, LIGHT_GREY, register_back_click);
    manager_register = push(btn, manager_register);
    tick_init(manager_register);

    callback1 = register_click;
    callback2 = register_key;
    callback3 = register_move;
    register_user[0] = '\0';
    register_password[0] = '\0';
    register_cover[0] = '\0';
}
