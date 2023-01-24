# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver=1.6.15
pkgrel=1
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go' 'git' 'btrfs-progs' 'libseccomp' 'containers-common' 'go-md2man')
provides=('container-runtime')
arch=('x86_64' 'aarch64')
license=("Apache")
source=("git+https://github.com/containerd/containerd.git#tag=v${pkgver}?signed")
validpgpkeys=("8C7A111C21105794B0E8A27BF58C5D0A4405ACDB") # Derek McGowan
sha256sums=('SKIP')

prepare() {
  # fix paths in service
  sed -i 's,/sbin,/usr/bin,;s,/usr/local,/usr,' $pkgname/containerd.service
}

build() {
  cd "${pkgname}" 
  export GOFLAGS="-trimpath -mod=readonly -modcacherw"
  make VERSION=v$pkgver GO_BUILD_FLAGS="-trimpath -mod=readonly -modcacherw" GO_GCFLAGS="" EXTRA_LDFLAGS="-buildid="
  make VERSION=v$pkgver man
}

check() {
  cd "${pkgname}" 
  # Ugly, but they are trying to do priviledged operations during testing
  GOFLAGS="-trimpath" make test || true
}

package() {
  cd "${pkgname}" 
  make PREFIX=/usr DESTDIR="$pkgdir/" install
  install -Dm644 containerd.service "$pkgdir"/usr/lib/systemd/system/containerd.service
  install -Dm644 man/*.8 -t "$pkgdir/usr/share/man/man8"
  install -Dm644 man/*.5 -t "$pkgdir/usr/share/man/man5"
}
