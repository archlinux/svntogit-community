# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver=1.2.5
_commit=bb71b10fd8f58240ca47fbb579b9d1028eea7c84
pkgrel=1
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go' 'git' 'btrfs-progs' 'libseccomp')
arch=('x86_64')
license=("APACHE")
source=("$pkgname-$pkgver.tar.gz::https://github.com/containerd/containerd/archive/v$pkgver.tar.gz")
sha256sums=('b92819bde71de947329814a3c649b8adb106cc03be16aae217b94297f4b843a1')

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
