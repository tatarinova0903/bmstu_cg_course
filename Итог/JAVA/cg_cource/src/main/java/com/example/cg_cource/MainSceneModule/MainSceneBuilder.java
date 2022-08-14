package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Helpers.ScreenConstants;

public class MainSceneBuilder {
    public static MainScene build() {
        MainGroup mainGroup = new MainGroup();
        MainScene scene = new MainScene(mainGroup, ScreenConstants.Main.WIDTH, ScreenConstants.Main.HEIGHT);
        return scene;
    }
}
