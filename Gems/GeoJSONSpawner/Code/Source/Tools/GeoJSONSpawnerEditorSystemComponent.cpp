/**
 * Copyright (C) Robotec AI - All Rights Reserved
 *
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders. If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.
 */

#include "GeoJSONSpawnerEditorSystemComponent.h"
#include <AzCore/Serialization/SerializeContext.h>

#include <GeoJSONSpawner/GeoJSONSpawnerTypeIds.h>

namespace GeoJSONSpawner
{
    AZ_COMPONENT_IMPL(
        GeoJSONSpawnerEditorSystemComponent,
        "GeoJSONSpawnerEditorSystemComponent",
        GeoJSONSpawnerEditorSystemComponentTypeId,
        BaseSystemComponent);

    void GeoJSONSpawnerEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<GeoJSONSpawnerEditorSystemComponent, GeoJSONSpawnerSystemComponent>()->Version(0);
        }
    }

    void GeoJSONSpawnerEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("GeoJSONSpawnerEditorService"));
    }

    void GeoJSONSpawnerEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("GeoJSONSpawnerEditorService"));
    }

    void GeoJSONSpawnerEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void GeoJSONSpawnerEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void GeoJSONSpawnerEditorSystemComponent::Activate()
    {
        GeoJSONSpawnerSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void GeoJSONSpawnerEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        GeoJSONSpawnerSystemComponent::Deactivate();
    }

} // namespace GeoJSONSpawner
