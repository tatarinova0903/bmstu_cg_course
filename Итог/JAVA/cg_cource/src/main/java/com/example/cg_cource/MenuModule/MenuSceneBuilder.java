package com.example.cg_cource.MenuModule;

import com.example.cg_cource.Helpers.Constants;
import com.example.cg_cource.MainSceneModule.MainGroup;

public class MenuSceneBuilder {
    public static MenuScene build(MainGroup group) {
        MenuStack menu = new MenuStack(group);
        MenuScene menuScene = new MenuScene(menu, Constants.Menu.WIDTH, Constants.Main.HEIGHT);
        return menuScene;
    }
}
