# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Mirco Tischler <mt-ml at gmx dot de>

pkgname=fwupd
pkgver=1.2.10
pkgrel=1
pkgdesc="A simple daemon to allow session software to update firmware"
arch=(x86_64)
url="https://github.com/hughsie/fwupd"
license=(LGPL)
depends=(libxmlb efivar python libsmbios libgusb
         libsoup json-glib gcab libarchive gpgme
         libgudev polkit shared-mime-info modemmanager)
makedepends=(meson valgrind gobject-introspection gtk-doc
             python-cairo noto-fonts noto-fonts-cjk python-gobject vala
             bash-completion python-pillow help2man gnu-efi-libs)
optdepends=('tpm2-abrmd: TPM2 support'
            'tpm2-tools: TPM2 support')
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
sha256sums=('4bee2032da8e3b690ecdc9a8a5662ea9b8287f72ba557758aa5321128f7ed646' 'SKIP')
validpgpkeys=(163EB50119225DB3DF8F49EA17ACBA8DFA970E17) # Richard Hughes <richard@hughsie.com>

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
    # Move D-BUS policy
    mv "${pkgdir}"/{etc,usr/share}/dbus-1/system.d
    rmdir "${pkgdir}"/etc/dbus-1
    # Remove the tests
    rm -r "${pkgdir}"/usr/share/installed-tests/
}
