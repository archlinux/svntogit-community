# Maintainer: Sébastien "Seblu" Luttringer
# Maintainer: Morten Linderud <foxboron@archlinux.org>

pkgname=docker
pkgver=20.10.2
pkgrel=1
epoch=1
pkgdesc='Pack, ship and run any application as a lightweight container'
arch=('x86_64')
url='https://www.docker.com/'
license=('Apache')
depends=('glibc' 'bridge-utils' 'iproute2' 'device-mapper' 'sqlite' 'systemd-libs'
         'libseccomp' 'libtool' 'runc' 'containerd')
makedepends=('git' 'go' 'btrfs-progs' 'cmake' 'systemd' 'go-md2man' 'sed')
optdepends=('btrfs-progs: btrfs backend support'
            'pigz: parallel gzip compressor support')
# https://github.com/moby/moby/tree/v20.10.0/hack/dockerfile/install
_TINI_COMMIT=de40ad007797e0dcd8b7126f27bb87401d224240
_LIBNETWORK_COMMIT=fa125a3512ee0f6187721c88582bf8c4378bd4d7
_BUILDX_COMMIT=11057da37336192bfc57d81e02359ba7ba848e4a
_APP_COMMIT=9d2c67f87b7338eb1a0fa2f18eb81af3d2aac0e1
source=("git+https://github.com/docker/cli.git#tag=v$pkgver"
        "git+https://github.com/moby/moby.git#tag=v$pkgver"
        "git+https://github.com/docker/libnetwork.git#commit=$_LIBNETWORK_COMMIT"
        "git+https://github.com/krallin/tini.git#commit=$_TINI_COMMIT"
        "git+https://github.com/docker/buildx.git#commit=$_BUILDX_COMMIT"
        "git+https://github.com/docker/app.git#commit=$_APP_COMMIT"
        "$pkgname.sysusers")
sha256sums=('SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            '541826011a9836d05a2f42293d5f1beadf2ca8d89fb604487d61a013505678eb')

prepare(){
  cd cli
  sed -i 's/-v md2man/-v go-md2man/' scripts/docs/generate-man.sh
  sed -i 's/md2man/go-md2man/' man/md2man-all.sh
}

# create a fake go path directory and pushd into it
# $1 real directory
# $2 gopath directory
_fake_gopath_pushd() {
  mkdir -p "$GOPATH/src/${2%/*}"
  rm -f "$GOPATH/src/$2"
  ln -rsT "$1" "$GOPATH/src/$2"
  pushd  "$GOPATH/src/$2" >/dev/null
}

_fake_gopath_popd() {
  popd >/dev/null
}

build() {
  ### globals
  export GOPATH="$srcdir"
  export PATH="$GOPATH/bin:$PATH"
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export CGO_LDFLAGS="${LDFLAGS}"
  export LDFLAGS=""
  export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw -ldflags=-linkmode=external"

  ### cli
  echo 'Building cli'
  _fake_gopath_pushd cli github.com/docker/cli
  DISABLE_WARN_OUTSIDE_CONTAINER=1 make VERSION=$pkgver dynbinary
  make manpages
  _fake_gopath_popd

  ### daemon
  echo 'Building daemon'
  _fake_gopath_pushd moby github.com/docker/docker
  DOCKER_GITCOMMIT=$(cd "$srcdir"/moby && git rev-parse --short HEAD) \
    DOCKER_BUILDTAGS='seccomp journald apparmor' \
    VERSION=$pkgver \
    hack/make.sh dynbinary
  _fake_gopath_popd

  ### docker proxy
  echo 'Building docker-proxy'
  _fake_gopath_pushd libnetwork github.com/docker/libnetwork
  go build github.com/docker/libnetwork/cmd/proxy
  _fake_gopath_popd

  ### docker-init
  echo 'Building docker-init'
  _fake_gopath_pushd tini github.com/krallin/tini
  cmake .
  # we must use the static binary because it's started in a foreign os
  make tini-static
  _fake_gopath_popd

  ### app cli plugin
  echo 'Building app cli plugin'
  _fake_gopath_pushd app github.com/docker/app
  make dynamic
  _fake_gopath_popd

  ### buildx cli plugin
  echo 'Building buildx cli plugin'
  _fake_gopath_pushd buildx github.com/docker/buildx
  go build -o docker-buildx -ldflags "-X github.com/docker/buildx/version.Version=$(git describe --match 'v[0-9]*' --always --tags)-tp-docker \
                                      -X github.com/docker/buildx/version.Revision=$(git rev-parse HEAD) \
                                      -X github.com/docker/buildx/version.Package=github.com/docker/buildx \
                                      -X main.experimental=1 -linkmode=external" ./cmd/buildx
  _fake_gopath_popd

}

package() {
  ### proxy
  install -Dm755 libnetwork/proxy "$pkgdir/usr/bin/docker-proxy"
  ### init
  install -Dm755 tini/tini-static "$pkgdir/usr/bin/docker-init"
  ### dockerd
  install -Dm755 moby/bundles/dynbinary-daemon/dockerd "$pkgdir"/usr/bin/dockerd
  ### systemd units
  cd "$srcdir"/moby/contrib
  install -Dm644 'init/systemd/docker.service' "$pkgdir/usr/lib/systemd/system/docker.service"
  install -Dm644 'init/systemd/docker.socket' "$pkgdir/usr/lib/systemd/system/docker.socket"
  # systemd rules
  install -Dm644 'udev/80-docker.rules' "$pkgdir/usr/lib/udev/rules.d/80-docker.rules"
  install -Dm644 "$srcdir/$pkgname.sysusers" "$pkgdir/usr/lib/sysusers.d/$pkgname.conf"
  ### cli
  cd "$srcdir"/cli
  # binary
  install -Dm755 build/docker "$pkgdir/usr/bin/docker"
  # completion
  install -Dm644 'contrib/completion/bash/docker' "$pkgdir/usr/share/bash-completion/completions/docker"
  install -Dm644 'contrib/completion/zsh/_docker' "$pkgdir/usr/share/zsh/site-functions/_docker"
  install -Dm644 'contrib/completion/fish/docker.fish' "$pkgdir/usr/share/fish/vendor_completions.d/docker.fish"
  # man
  install -dm755 "$pkgdir/usr/share/man"
  cp -r man/man* "$pkgdir/usr/share/man"
  # cli-plugins
  cd "$srcdir"/src/github.com/docker
  install -Dm755 app/bin/docker-app "$pkgdir/usr/lib/docker/cli-plugins/docker-app"
  install -Dm755 buildx/docker-buildx "$pkgdir/usr/lib/docker/cli-plugins/docker-buildx"
}

# vim:set ts=2 sw=2 et:
