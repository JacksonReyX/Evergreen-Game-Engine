//
// Created by Jackson Reynolds on 10/28/26.
//

class DashSystem : public System {
    public:
        DashSystem() {
            requiredComponent<MoveableComponent>();
            requiredComponent<TransformComponent>();
        }

        void update() {

        }
};
