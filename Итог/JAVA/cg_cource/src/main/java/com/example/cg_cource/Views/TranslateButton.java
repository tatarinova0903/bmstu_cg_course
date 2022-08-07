package com.example.cg_cource.Views;

import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class TranslateButton extends Button {
    public TranslateButton(TranslateButtonType type) {
        super();
        Image img = null;
        switch (type) {
            case PLUS -> img = new Image(getClass().getResourceAsStream("/images/plus.png"));
            case MINUS -> img = new Image(getClass().getResourceAsStream("/images/minus.png"));
        }
        ImageView view = new ImageView(img);
        view.setFitHeight(10);
        view.setPreserveRatio(true);
//        setHeight(10);
//        setWidth(10);
        setGraphic(view);
    }
}
