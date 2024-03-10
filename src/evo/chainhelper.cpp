// Copyright (c) 2024 The Dash Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <evo/chainhelper.h>

#include <consensus/params.h>
#include <evo/specialtxman.h>
#include <masternode/payments.h>

CChainstateHelper::CChainstateHelper(CCreditPoolManager& cpoolman, CDeterministicMNManager& dmnman, CMNHFManager& mnhfman, CGovernanceManager& govman,
                                     llmq::CQuorumBlockProcessor& qblockman, const Consensus::Params& consensus_params,
                                     const CMasternodeSync& mn_sync, const CSporkManager& sporkman, const llmq::CChainLocksHandler& clhandler)
    : mn_payments{std::make_unique<CMNPaymentsProcessor>(dmnman, govman, consensus_params, mn_sync, sporkman)},
      special_tx{std::make_unique<CSpecialTxProcessor>(cpoolman, dmnman, mnhfman, qblockman, consensus_params, clhandler)}
{}

CChainstateHelper::~CChainstateHelper() = default;
