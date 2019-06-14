# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver=1.2.7
_commit=85f6aa58b8a3170aec9824568f7a31832878b603
pkgrel=1
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go' 'git' 'btrfs-progs' 'libseccomp')
arch=('x86_64')
license=("Apache")
source=("$pkgname-$pkgver.tar.gz::https://github.com/containerd/containerd/archive/v$pkgver.tar.gz")
sha256sums=('7179c709a0d187708a1eeddcbdecd7206b2c642dc4413bcdb049cd6b38d06801')


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

check() {
  cd src/github.com/containerd/containerd
  make test
}

package() {
  export GOPATH="$srcdir"
  cd src/github.com/containerd/containerd
  make install DESTDIR="$pkgdir/usr"
  install -Dm644 containerd.service "$pkgdir"/usr/lib/systemd/system/containerd.service
}
