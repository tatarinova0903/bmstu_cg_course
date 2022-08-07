package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Helpers.ScreenConstants;
import javafx.scene.Camera;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;

public class MainScene extends Scene {
    private Camera camera = new PerspectiveCamera(true);
    private MainGroup group;

    public MainScene(Parent parent, double v, double v1) {
        super(parent, v, v1);
        group = (MainGroup) parent;
        setFill(Color.RED);
        setCamera(camera);

        camera.translateZProperty().set(-1000);

        camera.setNearClip(1);
        camera.setFarClip(1500);
    }

    public void keyboardDidTap(KeyEvent keyEvent) {
        switch (keyEvent.getCode()) {
            case W -> group.roomGroup.translateZProperty().set(
                    group.roomGroup.getTranslateZ() + ScreenConstants.Zoom.COORD_CHANGE
            );
            case S -> group.roomGroup.translateZProperty().set(
                    group.roomGroup.getTranslateZ() - ScreenConstants.Zoom.COORD_CHANGE
            );
            case UP -> group.roomGroup.rotateByX(-10);
            case DOWN -> group.roomGroup.rotateByX(10);
            case LEFT -> group.roomGroup.rotateByY(10);
            case RIGHT -> group.roomGroup.rotateByY(-10);
        }
    }
}
