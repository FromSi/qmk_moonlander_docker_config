```bash
# First build
mkdir moonlander && \
cd ./moonlander && \
git clone --depth 1 git@github.com:FromSi/qmk_moonlander_docker_config.git && \
git clone --depth 1 --recurse-submodules --branch firmware23 git@github.com:zsa/qmk_firmware.git && \
cp -r ./qmk_moonlander_docker_config ./qmk_firmware/keyboards/moonlander/keymaps/qmk_moonlander_docker_config && \
cd ./qmk_firmware && \
util/docker_build.sh moonlander:qmk_moonlander_docker_config:flash 
```

```bash
# Remove config after changed
rm -rf ./qmk_firmware/keyboards/moonlander/keymaps/qmk_moonlander_docker_config && \
cp -r ./qmk_moonlander_docker_config ./qmk_firmware/keyboards/moonlander/keymaps/qmk_moonlander_docker_config && \
cd ./qmk_firmware
```

```bash
util/docker_build.sh moonlander:qmk_moonlander_docker_config:flash 
```

```bash
# Remove
rm -rf ./moonlander && \
docker image ls | grep 'ghcr.io/qmk/qmk_cli' | awk '{print $3}' | xargs docker image rm
```
