package com.example.cg_cource;

import javafx.scene.Camera;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;

class MainScene extends Scene {
    private Camera camera = new PerspectiveCamera(true);

    public MainScene(Parent parent, double v, double v1) {
        super(parent, v, v1);
        setFill(Color.SILVER);
        setCamera(camera);

        camera.translateZProperty().set(-500);

        camera.setNearClip(1);
        camera.setFarClip(1000);
    }

    void keyboardDidTap(KeyEvent keyEvent) {
        switch (keyEvent.getCode()) {
            case W -> camera.translateZProperty().set(camera.getTranslateZ() + 10);
            case S -> camera.translateZProperty().set(camera.getTranslateZ() - 10);
        }
    }
}
