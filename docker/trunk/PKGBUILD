# Maintainer: Sébastien "Seblu" Luttringer

pkgname=docker
pkgver=18.09.8
pkgrel=1
epoch=1
pkgdesc='Pack, ship and run any application as a lightweight container'
arch=('x86_64')
url='https://www.docker.com/'
license=('Apache')
depends=('glibc' 'bridge-utils' 'iproute2' 'device-mapper' 'sqlite' 'systemd-libs'
         'libseccomp' 'libtool' 'runc' 'containerd')
makedepends=('git' 'go' 'btrfs-progs' 'cmake' 'systemd' 'go-md2man')
optdepends=('btrfs-progs: btrfs backend support'
            'pigz: parallel gzip compressor support')
# don't strip binaries! A sha1 is used to check binary consistency.
options=('!strip' '!buildflags')
# Use exact commit version from Dockerfile, see them in:
# https://github.com/docker/docker-ce/blob/master/components/engine/hack/dockerfile/install/
_TINI_COMMIT=fec3683b971d9c3ef73f284f176672c44b448662
_LIBNETWORK_COMMIT=e7933d41e7b206756115aa9df5e0599fc5169742
source=("git+https://github.com/docker/docker-ce.git#tag=v$pkgver"
        "git+https://github.com/docker/libnetwork.git#commit=$_LIBNETWORK_COMMIT"
        "git+https://github.com/krallin/tini.git#commit=$_TINI_COMMIT"
        "git+https://github.com/spf13/cobra.git"
        "$pkgname.sysusers")
md5sums=('SKIP'
         'SKIP'
         'SKIP'
         'SKIP'
         '9a8b2744db23b14ca3cd350fdf73c179')


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
  msg2 'Checking commit mismatch'
  (
  local _cfile
  for _cfile in tini proxy; do
    . "$srcdir/docker-ce/components/engine/hack/dockerfile/install/$_cfile.installer"
  done
  local _commit _pkgbuild _dockerfile
  for _commit in LIBNETWORK TINI; do
    _pkgbuild=_${_commit}_COMMIT
    _dockerfile=${_commit}_COMMIT
    if [[ ${!_pkgbuild} != ${!_dockerfile} ]]; then
      error "Invalid $_commit commit, should be ${!_dockerfile}"
      return 1
    fi
  done
  )

  ### globals
  export GOPATH="$srcdir"
  export PATH="$GOPATH/bin:$PATH"

  ### cli
  msg2 'Building cli'
  _fake_gopath_pushd docker-ce/components/cli github.com/docker/cli
  DISABLE_WARN_OUTSIDE_CONTAINER=1 make VERSION=$pkgver-ce dynbinary
  _fake_gopath_popd

  ### daemon
  msg2 'Building daemon'
  _fake_gopath_pushd docker-ce/components/engine github.com/docker/docker
  DOCKER_GITCOMMIT=$(cd "$srcdir"/docker-ce && git rev-parse --short HEAD) \
    DOCKER_BUILDTAGS='seccomp journald' \
    VERSION=$pkgver-ce \
    hack/make.sh dynbinary
  _fake_gopath_popd

  ### docker man pages
  msg2 'Building man pages'
  mkdir -p src/github.com/spf13
  ln -rsfT cobra src/github.com/spf13/cobra
  # use docker-ce cli version because they mess up with man dir
  _fake_gopath_pushd docker-ce/components/cli github.com/docker/cli
  make manpages 2>/dev/null
  _fake_gopath_popd

  ### docker proxy
  msg2 'Building docker-proxy'
  _fake_gopath_pushd libnetwork github.com/docker/libnetwork
  go build -ldflags='-linkmode=external' github.com/docker/libnetwork/cmd/proxy
  _fake_gopath_popd

  ### docker-init
  msg2 'Building docker-init'
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
  install -Dm755 {bundles/latest/dynbinary-daemon,"$pkgdir"/usr/bin}/dockerd
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
  install -Dm755 build/docker "$pkgdir/usr/bin/docker"
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
}

# vim:set ts=2 sw=2 et:
