# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver="1.4.0"
_commit=09814d48d50816305a8e6c1a4ae3e2bcc4ba725a
pkgrel=3
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go' 'git' 'btrfs-progs' 'libseccomp')
arch=('x86_64')
license=("Apache")
source=("$pkgname-$pkgver.tar.gz::https://github.com/containerd/containerd/archive/v$pkgver.tar.gz"
        "consume-fifo.patch::https://github.com/containerd/containerd/commit/9efd7381811e46b78f5b1f7bb2119ceb02eb5a82.patch"
        "fix-health.patch::https://github.com/containerd/containerd/commit/5f9d15eaac5d20b252f956bd80da94ec1b8244f5.patch")
sha256sums=('d6284c69e1933e4c05fe285feebef461efe8cd2030634dcf1cbdcde46abe86be'
            'a1f044e05b411a7f48de5ba7c572dfa45e075b1ecf521129f2b3319bb6aae3b1'
            '432be5cb48649a35c456676119a3ec86ac51cbc2d8fed7e41033de1c8e019d8b')

prepare() {
  mkdir -p src/github.com/containerd
  ln -rTsf $pkgname-$pkgver src/github.com/containerd/containerd

  # fix paths in service
  sed -i 's,/sbin,/usr/bin,;s,/usr/local,/usr,' $pkgname-$pkgver/containerd.service

  cd $pkgname-$pkgver
  patch -Np1 < "$srcdir/consume-fifo.patch"
  patch -Np1 < "$srcdir/fix-health.patch"
}

build() {
  export GOPATH="$srcdir"
  cd src/github.com/containerd/containerd
  export GOFLAGS="-trimpath -mod=readonly -modcacherw"
  make VERSION=v$pkgver.m REVISION=$_commit.m
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
