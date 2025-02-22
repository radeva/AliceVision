// This file is part of the AliceVision project.
// Copyright (c) 2016 AliceVision contributors.
// Copyright (c) 2012 openMVG contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <aliceVision/sfmData/SfMData.hpp>

#include <map>

namespace aliceVision {
namespace sfmData {

/**
 * @brief compute a view UID
 * @param[in] view
 * @return UID
 */
std::size_t computeViewUID(const View& view);

/**
 * @brief Update all viewID referenced in the observation of each landmark according
 * to the provided mapping.
 *
 * @param[in,out] landmarks The landmarks to update.
 * @param[in] oldIdToNew The mapping between the old ID and the reconmputed UID.
 */
void updateStructureWithNewUID(Landmarks& landmarks, const std::map<std::size_t, std::size_t>& oldIdToNew);

/**
 * @brief It perform a sanity check on a list of Landmarks and check if the viewIDs
 * in the observations of each landmark has a corresponding ID in the list of views.
 * @param[in] landmarks A list of landmarks.
 * @param[in] views A list of views.
 */
void sanityCheckLandmarks(const Landmarks& landmarks, const Views& views);

/**
 * @brief Recompute the UID from the metadata of the original input images and
 * modify the ID if it's not the same.
 *
 * @param[in,out] sfmdata The sfmdata scene for which to recompute the UID.
 * @param[out] oldIdToNew A map that holds the mapping between the old ID and the
 * reconmputed UID.
 * @param[in] sanityCheck Enable a sanity check at the end to assure that the
 * observations of 3D points and the control points have been correctly updated.
 */
void regenerateUID(SfMData& sfmdata, std::map<std::size_t, std::size_t>& oldIdToNew, bool sanityCheck = false);

/**
 * @brief Update all viewID of a list of view by replacing them with the UID.
 *
 * @param[in,out] views The list of views to update
 * @param[out] oldIdToNew oldIdToNew A map that holds the mapping between the
 * old ID and the reconmputed UID.
 */
void regenerateViewUIDs(Views& views, std::map<std::size_t, std::size_t>& oldIdToNew);

}  // namespace sfmData
}  // namespace aliceVision
