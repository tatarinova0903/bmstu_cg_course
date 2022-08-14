package com.example.cg_cource.Views;

import com.example.cg_cource.Helpers.MenuEvent;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class TranslateButton extends Button {
    public TranslateButton(MenuEvent menuEvent) {
        super();
        Image img = null;
        switch (menuEvent) {
            case PLUS -> img = new Image(getClass().getResourceAsStream("/images/plus.png"));
            case MINUS -> img = new Image(getClass().getResourceAsStream("/images/minus.png"));
            case ROTATE_DOWN -> img = new Image(getClass().getResourceAsStream("/images/down.png"));
            case ROTATE_UP -> img = new Image(getClass().getResourceAsStream("/images/up.png"));
            case ROTATE_LEFT -> img = new Image(getClass().getResourceAsStream("/images/left.png"));
            case ROTATE_RIGHT -> img = new Image(getClass().getResourceAsStream("/images/right.png"));
        }
        ImageView view = new ImageView(img);
        view.setFitHeight(10);
        view.setPreserveRatio(true);
        setGraphic(view);
    }
}
