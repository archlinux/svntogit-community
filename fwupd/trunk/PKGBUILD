# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Mirco Tischler <mt-ml at gmx dot de>

pkgname=fwupd
pkgver=1.3.2
pkgrel=1
pkgdesc="A simple daemon to allow session software to update firmware"
arch=(x86_64)
url="https://github.com/fwupd/fwupd"
license=(LGPL)
depends=(libxmlb efivar python libsmbios libgusb
         libsoup json-glib gcab libarchive gpgme
         libgudev polkit shared-mime-info modemmanager)
optdepends=('tpm2-tss: UEFI plugin')
makedepends=(meson valgrind gobject-introspection gtk-doc
             python-cairo noto-fonts noto-fonts-cjk python-gobject vala
             bash-completion python-pillow help2man gnu-efi-libs tpm2-tss)
checkdepends=(umockdev)
backup=('etc/fwupd/daemon.conf'
        'etc/fwupd/redfish.conf'
        'etc/fwupd/remotes.d/dell-esrt.conf'
        'etc/fwupd/remotes.d/fwupd-tests.conf'
        'etc/fwupd/remotes.d/lvfs-testing.conf'
        'etc/fwupd/remotes.d/lvfs.conf'
        'etc/fwupd/remotes.d/vendor-directory.conf'
        'etc/fwupd/remotes.d/vendor.conf'
        'etc/fwupd/uefi.conf')
source=("https://people.freedesktop.org/~hughsient/releases/${pkgname}-${pkgver}.tar.xz"{,.asc})
sha256sums=('33a52b6140b6b0860db649674d0b9af23387328cf92a2eafd8f3a766f365891e'
            'SKIP')
validpgpkeys=(163EB50119225DB3DF8F49EA17ACBA8DFA970E17) # Richard Hughes <richard@hughsie.com>

prepare() {
  cd ${pkgname}-${pkgver}

  # This tests are failing inside a chroot
  sed -i "/test('uefi-self-test', e)/d" plugins/uefi/meson.build
  sed -i "/test('dell-self-test', e)/d" plugins/dell/meson.build
}

build() {
    cd ${pkgname}-${pkgver}
    arch-meson -D b_lto=false ../build
    ninja -v -C ../build
}

check() {
    cd build
    meson test
}

package() {
    DESTDIR="${pkgdir}" ninja -C build install
    # Fixup mode to match polkit
    install -d -o root -g 102 -m 750 "${pkgdir}"/usr/share/polkit-1/rules.d
    # Remove the tests
    rm -r "${pkgdir}"/usr/share/installed-tests/
}
