#!/bin/bash
apt-get update
wget https://github.com/ipfs/go-ipfs/releases/download/v0.6.0/go-ipfs_v0.6.0_linux-amd64.tar.gz
tar xvfz go-ipfs_v0.6.0_linux-amd64.tar.gz
rm go-ipfs_v0.6.0_linux-amd64.tar.gz 
mv go-ipfs/ipfs /usr/local/bin
rm -rf go-ipfs

# init repo
echo 'export IPFS_PATH=/data/ipfs' >>~/.bash_profile
source ~/.bash_profile
mkdir -p $IPFS_PATH
ipfs init -p server

ipfs config Datastore.StorageMax 20GB
# uncomment if you want direct access to the instance's gateway
ipfs config Addresses.Gateway /ip4/0.0.0.0/tcp/8080
ipfs config Addresses.API /ip4/0.0.0.0/tcp/5001
ipfs config --json API.HTTPHeaders.Access-Control-Allow-Origin "[\"*\"]"
ipfs config --json API.HTTPHeaders.Access-Control-Allow-Credentials "[\"true\"]"

bash -c 'cat >/lib/systemd/system/ipfs.service <<EOL
[Unit]
Description=ipfs daemon
[Service]
ExecStart=/usr/local/bin/ipfs daemon --enable-gc
Restart=always
Environment="IPFS_PATH=/data/ipfs"
[Install]
WantedBy=multi-user.target
EOL'



bash -c 'cat > /data/ipfs/swarm.key <<EOL
/key/swarm/psk/1.0.0/
/base16/
96d16ebec087f5e6f3247c50ea9b2f24ac91a17d5b755e7c85071891474c6584
EOL'

ipfs bootstrap rm --all
ipfs bootstrap add /ip4/13.127.174.128/tcp/4001/ipfs/QmepeqPz6xwW5Y8L3Q9FR8BWA9HiArzcRmYZRoCpiUESwX

ipfs config Datastore.StorageMax 20GB
ipfs config Addresses.Gateway /ip4/0.0.0.0/tcp/8080
ipfs config Addresses.API /ip4/0.0.0.0/tcp/5001
ipfs config --json API.HTTPHeaders.Access-Control-Allow-Origin "[\"*\"]"
ipfs config --json API.HTTPHeaders.Access-Control-Allow-Credentials "[\"true\"]"


systemctl daemon-reload
systemctl enable ipfs.service
systemctl start ipfs
systemctl status ipfs

ipfs daemon & 
