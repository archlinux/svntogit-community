# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver=1.4.3
pkgrel=1
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go' 'git' 'btrfs-progs' 'libseccomp' 'containers-common')
provides=('container-runtime')
arch=('x86_64')
license=("Apache")
source=("git+https://github.com/containerd/containerd.git#tag=v${pkgver}?signed")
validpgpkeys=("8C7A111C21105794B0E8A27BF58C5D0A4405ACDB") # Derek McGowan
sha256sums=('SKIP')

prepare() {
  mkdir -p src/github.com/containerd
  ln -rTsf $pkgname src/github.com/containerd/containerd

  # fix paths in service
  sed -i 's,/sbin,/usr/bin,;s,/usr/local,/usr,' $pkgname/containerd.service
}

build() {
  export GOPATH="$srcdir"
  cd src/github.com/containerd/containerd
  export GOFLAGS="-trimpath -mod=readonly -modcacherw"
  make VERSION=v$pkgver
}

check() {
  cd src/github.com/containerd/containerd
  GOFLAGS="" make test
}

package() {
  export GOPATH="$srcdir"
  cd src/github.com/containerd/containerd
  make install DESTDIR="$pkgdir/usr"
  install -Dm644 containerd.service "$pkgdir"/usr/lib/systemd/system/containerd.service
}
