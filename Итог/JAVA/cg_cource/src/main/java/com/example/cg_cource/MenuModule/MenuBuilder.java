package com.example.cg_cource.MenuModule;

import com.example.cg_cource.MainSceneModule.MainGroup;

public class MenuBuilder {
    public static MenuStack build(MainGroup group) {
        MenuStack menu = new MenuStack(group);
        return menu;
    }
}
