# Era Swap IPFS Specification

Version 0.1.0 - Updated 16 Dec @ 2:06pm

## Abstract

IPFS is a platform to store files on a distributed system (this system consists of inter-connected IPFS nodes). Just like you can store files on Google Drive or Dropbox and pay them for doing that and share link to friends for accessing the files. These are centralized companies that rent storage space. In IPFS general users can install IPFS node to rent their hard drive space to earn digital currency. Here too, a user wanting to upload file has to pay for that. But the variable part is that, user can choose to have their files in multiple nodes to maximise the chance for availability as well as quick file loading. Obviously, uploading files to multiple nodes will require cost to be paid by the user in proportion to the number of nodes user wants the files to be uploaded. We want to leverage this technology in our ecosystem dApps.

## Utility brief of IPFS in our ecosystem dApps
When a user is uploading a profile picture on a platform like SwappersWall (social media platform), it is not feasible to efficient to store the image data in the blockchain, as it will increase the blockchain size and anyone making the copy of blockchain will need to have the image downloaded. As these images are required occasionally when someone visits the profile page, they can be stored off-chain and retrieved on demand and an only hash of the image can be stored in the blockchain should be enough to fetch the image from an off-chain source and verify it.

We aim to utilise IPFS for storing files off-chain. But following challenges are faced:

1. Paying to upload a profile picture is very foreign to general user (facebook)
2. If IPFS pricing in other currency than ES (e.g. Filecoin), then it increases the difficulty to just upload a profile picture on platform like SwappersWall. (edit 9 sept: AFAIK, there is no tokenomics in IPFS).
3. Infrastructure which make this possible like Filecoin, are still in development, i.e. not ready.
4. This also applies to other utilities like KYC documents and attachments in messaging.

## Solution

So to make our platforms possible, we propose the following solution until other platforms have been developed and matured.

We plan to duplicate the idea of Filecoin for Era Swap Ecosystem in a centralized way for now (edit 9 sept: TODO: this needs to be updated with the decentralised plan) to prevent involvement of an extra currency (though a discussion would be nice with their team if ES can be instead involved instead for better UX). We can start an Era Swap Cloud service. We will setup multiple AWS servers in multiple zones in the world in which user can submit their profile picture and pay for it. User can also choose to upload profile picture to multiple zones and pay more amount. This will feature the following things:

1. User can pay in ES depending on his profile photo size and number of servers user wants their profile photo to exist in the world.
2. Since the user has to pay for their data availability for (1 year or higher time), there will not be data spamming which will fill the servers with data.
3. Users can choose to delete their data from being available and get back the balance amount.
4. Infrastructure costs can be covered with this strategy.
5. Platforms can be independent of roadmap of other platforms like Filecoin.
6. Later, we can have our users switch to other model i.e. we can give option to advanced users to use Filecoin too or normal users can use our centralized service.

## Development Plan

A proper system design needs to be made to eliminate downtime possibilities due to multiple attack vectors. Every concerned developer of Era Swap Team is requested to have researched enough on topics mentioned in this concept specification as proceeding with this concept implies that this would probably have a use case in the platform you are developing too. We will have a powerful and constructive discussion soon.
