package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Helpers.Constants;

public class MainSceneBuilder {
    public static MainScene build() {
        MainGroup mainGroup = new MainGroup();
        MainScene scene = new MainScene(mainGroup, Constants.Main.WIDTH, Constants.Main.HEIGHT);
        return scene;
    }
}
