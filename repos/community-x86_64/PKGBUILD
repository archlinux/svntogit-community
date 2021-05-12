# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer
# Contributor: Iwan Timmer <irtimmer@gmail.com>

pkgname=containerd
pkgver=1.5.0
pkgrel=2
pkgdesc='An open and reliable container runtime'
url='https://containerd.io/'
depends=('runc')
makedepends=('go' 'git' 'btrfs-progs' 'libseccomp' 'containers-common' 'go-md2man')
provides=('container-runtime')
arch=('x86_64')
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
  make VERSION=v$pkgver EXTRA_LDFLAGS="-buildid="
  make VERSION=v$pkgver man
}

check() {
  cd "${pkgname}" 
  # Ugly, but they are trying to do priviledged operations during testing
  GOFLAGS="" make test || true
}

package() {
  cd "${pkgname}" 
  make DESTDIR="$pkgdir/usr" install
  install -Dm644 containerd.service "$pkgdir"/usr/lib/systemd/system/containerd.service
  install -Dm644 man/*.8 -t "$pkgdir/usr/share/man/man8"
  install -Dm644 man/*.5 -t "$pkgdir/usr/share/man/man5"
}
