
/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @generated by codegen project: GenerateComponentDescriptorH.js
 */

#pragma once

#include "ModuleShadowNodes.h"
#include <react/renderer/core/ConcreteComponentDescriptor.h>

namespace facebook {
namespace react {

class ModuleComponentDescriptor : public ConcreteComponentDescriptor<ModuleShadowNode> {
public:
    ModuleComponentDescriptor(ComponentDescriptorParameters const &parameters): ConcreteComponentDescriptor(parameters) {
        
    }
    
    // TODO think about it 
    virtual ShadowNode::Shared createShadowNode(
        const ShadowNodeFragment &fragment,
        ShadowNodeFamily::Shared const &family) const override {
      auto shadowNode =
            std::make_shared<ModuleShadowNode>(ShadowNodeFragment{fragment.props, nullptr}, family, getTraits());
      ShadowNode::SharedListOfShared registeredComponents = fragment.children;
            //
          /*  for (std::shared_ptr<const ShadowNode> sn : (*(fragment.children))) {
                int x = 5;
                int y = x;
            }*/
            //const std::shared_ptr<const ShadowNode> sn = fragment.children[0];
            
            //
      adopt(shadowNode);

      return shadowNode;
    }
    
    // TODO fix this
    virtual ShadowNode::Unshared cloneShadowNode(
        const ShadowNode &sourceShadowNode,
        const ShadowNodeFragment &fragment) const override {
            auto shadowNode = std::make_shared<ModuleShadowNode>(sourceShadowNode, ShadowNodeFragment{});
        ShadowNode::SharedListOfShared registeredComponents = fragment.children;
        //
        const std::shared_ptr<const ShadowNode> sn = (*registeredComponents)[0];
        int x = 5;
        int y = x;
        //

        adopt(shadowNode);
        return shadowNode;
    }
    
    virtual ~ModuleComponentDescriptor(){}
};


} // namespace react
} // namespace facebook
