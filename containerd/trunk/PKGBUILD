# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver=1.1.4
_commit=9f2e07b1fc1342d1c48fe4d7bbb94cb6d1bf278b
pkgrel=1
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go-pie' 'git' 'btrfs-progs')
arch=('x86_64')
license=("APACHE")
source=("$pkgname-$pkgver.tar.gz::https://github.com/containerd/containerd/archive/v$pkgver.tar.gz")
sha256sums=('7482bf738cf4ec3712c7719006b4b7874f5e35f076d15efc8f10e03fa35bedaf')

prepare() {
  mkdir -p src/github.com/containerd
  ln -rTsf $pkgname-$pkgver src/github.com/containerd/containerd
  # fix paths in service
  sed -i 's,/sbin,/usr/bin,;s,/usr/local,/usr,' $pkgname-$pkgver/containerd.service
}

build() {
  export GOPATH="$srcdir"
  cd src/github.com/containerd/containerd
  make VERSION=v$pkgver.m REVISION=$_commit.m
}

package() {
  export GOPATH="$srcdir"
  cd src/github.com/containerd/containerd
  make install DESTDIR="$pkgdir/usr"
  install -Dm644 containerd.service "$pkgdir"/usr/lib/systemd/system/containerd.service
}

# vim:set ts=2 sw=2 et:
