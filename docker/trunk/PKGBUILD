# Maintainer: Sébastien "Seblu" Luttringer

pkgname=docker
pkgver=19.03.12
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
# don't strip binaries! A sha1 is used to check binary consistency.
options=('!strip' '!buildflags')
# Use exact commit version from Dockerfile, see them in:
# https://github.com/docker/docker-ce/blob/master/components/engine/hack/dockerfile/install/
_TINI_COMMIT=fec3683b971d9c3ef73f284f176672c44b448662
_LIBNETWORK_COMMIT=026aabaa659832804b01754aaadd2c0f420c68b6
_APP_TAG='v0.9.1-beta3'
source=("git+https://github.com/docker/docker-ce.git#tag=v$pkgver"
        "git+https://github.com/docker/libnetwork.git#commit=$_LIBNETWORK_COMMIT"
        "git+https://github.com/krallin/tini.git#commit=$_TINI_COMMIT"
        "git+https://github.com/spf13/cobra.git"
        "git+https://github.com/docker/buildx.git"
        "git+https://github.com/docker/app.git#tag=$_APP_TAG"
        "$pkgname.sysusers")
sha256sums=('SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            '541826011a9836d05a2f42293d5f1beadf2ca8d89fb604487d61a013505678eb')

prepare() {
  sed -i 's,/var/run,/run,' docker-ce/components/engine/contrib/init/systemd/docker.socket
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
  ### check my mistakes on commit version
  echo 'Checking commit mismatch'
  (
  local _cfile
  for _cfile in tini proxy; do
    . "$srcdir/docker-ce/components/engine/hack/dockerfile/install/$_cfile.installer"
  done
  local _commit _pkgbuild _dockerfile
  err=0
  for _commit in LIBNETWORK TINI; do
    _pkgbuild=_${_commit}_COMMIT
    _dockerfile=${_commit}_COMMIT
    if [[ ${!_pkgbuild} != ${!_dockerfile} ]]; then
      echo "Invalid $_commit commit, should be ${!_dockerfile}" >&2
      err=$(($err + 1))
    fi
  done
  return $err
  )

  ### globals
  export GOPATH="$srcdir"
  export PATH="$GOPATH/bin:$PATH"

  ### cli
  echo 'Building cli'
  _fake_gopath_pushd docker-ce/components/cli github.com/docker/cli
  DISABLE_WARN_OUTSIDE_CONTAINER=1 make VERSION=$pkgver-ce dynbinary
  _fake_gopath_popd

  ### app cli plugin
  echo 'Building app cli plugin'
  _fake_gopath_pushd app github.com/docker/app
  make dynamic
  _fake_gopath_popd

  ### buildx cli plugin
  echo 'Building buildx cli plugin'
  _fake_gopath_pushd buildx github.com/docker/buildx
  go build -o bin/docker-buildx -ldflags "-X github.com/docker/buildx/version.Version=$(git describe --match 'v[0-9]*' --always --tags)-tp-docker -X github.com/docker/buildx/version.Revision=$(git rev-parse HEAD) -X github.com/docker/buildx/version.Package=github.com/docker/buildx -X main.experimental=1" ./cmd/buildx
  go clean -modcache
  _fake_gopath_popd

  ### daemon
  echo 'Building daemon'
  _fake_gopath_pushd docker-ce/components/engine github.com/docker/docker
  DOCKER_GITCOMMIT=$(cd "$srcdir"/docker-ce && git rev-parse --short HEAD) \
    DOCKER_BUILDTAGS='seccomp journald apparmor' \
    VERSION=$pkgver-ce \
    hack/make.sh dynbinary
  _fake_gopath_popd

  ### docker man pages
  echo 'Building man pages'
  mkdir -p src/github.com/spf13
  ln -rsfT cobra src/github.com/spf13/cobra
  # use docker-ce cli version because they mess up with man dir
  _fake_gopath_pushd docker-ce/components/cli github.com/docker/cli
  make manpages 2>/dev/null
  _fake_gopath_popd

  ### docker proxy
  echo 'Building docker-proxy'
  _fake_gopath_pushd libnetwork github.com/docker/libnetwork
  go build -ldflags='-linkmode=external' github.com/docker/libnetwork/cmd/proxy
  _fake_gopath_popd

  ### docker-init
  echo 'Building docker-init'
  _fake_gopath_pushd tini github.com/krallin/tini
  cmake .
  # we must use the static binary because it's started in a foreign os
  make tini-static
  _fake_gopath_popd
}

package() {
  ### proxy
  install -Dm755 libnetwork/proxy "$pkgdir/usr/bin/docker-proxy"
  ### init
  install -Dm755 tini/tini-static "$pkgdir/usr/bin/docker-init"
  ### engine
  cd "$srcdir"/docker-ce/components/engine
  # binary
  install -Dm755 {bundles/dynbinary-daemon,"$pkgdir"/usr/bin}/dockerd
  # systemd
  install -Dm644 'contrib/init/systemd/docker.service' \
    "$pkgdir/usr/lib/systemd/system/docker.service"
  install -Dm644 'contrib/init/systemd/docker.socket' \
    "$pkgdir/usr/lib/systemd/system/docker.socket"
  install -Dm644 'contrib/udev/80-docker.rules' \
    "$pkgdir/usr/lib/udev/rules.d/80-docker.rules"
  install -Dm644 "$srcdir/$pkgname.sysusers" \
    "$pkgdir/usr/lib/sysusers.d/$pkgname.conf"
  # vim syntax
  install -Dm644 'contrib/syntax/vim/syntax/dockerfile.vim' \
    "$pkgdir/usr/share/vim/vimfiles/syntax/dockerfile.vim"
  install -Dm644 'contrib/syntax/vim/ftdetect/dockerfile.vim' \
    "$pkgdir/usr/share/vim/vimfiles/ftdetect/dockerfile.vim"
  ### cli
  cd "$srcdir"/docker-ce/components/cli
  # binary
  install -Dm755 {build,"$pkgdir"/usr/bin}/docker
  # completion
  install -Dm644 'contrib/completion/bash/docker' \
    "$pkgdir/usr/share/bash-completion/completions/docker"
  install -Dm644 'contrib/completion/zsh/_docker' \
    "$pkgdir/usr/share/zsh/site-functions/_docker"
  install -Dm644 'contrib/completion/fish/docker.fish' \
    "$pkgdir/usr/share/fish/vendor_completions.d/docker.fish"
  # man
  install -dm755 "$pkgdir/usr/share/man"
  cp -r man/man* "$pkgdir/usr/share/man"
  # cli-plugins
  cd "$srcdir"/src/github.com/docker
  install -Dm755 app/bin/docker-app "$pkgdir/usr/lib/docker/cli-plugins/docker-app"
  install -Dm755 buildx/bin/docker-buildx "$pkgdir/usr/lib/docker/cli-plugins/docker-buildx"
}

# vim:set ts=2 sw=2 et:
