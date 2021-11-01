# Maintainer: Bruno Pagani <archange@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Mirco Tischler <mt-ml at gmx dot de>

pkgname=fwupd
pkgver=1.7.1
pkgrel=1
pkgdesc="Simple daemon to allow session software to update firmware"
arch=(x86_64)
url="https://github.com/fwupd/fwupd"
license=(LGPL)
depends=(libxmlb efivar python libsmbios libgusb
         polkit shared-mime-info tpm2-tss flashrom
         libjcat fwupd-efi gcab hicolor-icon-theme
         libarchive.so libcurl.so
         libjson-glib-1.0.so libgudev-1.0.so libmm-glib.so
         libqmi-glib.so libprotobuf-c.so)
optdepends=(
    'udisks2: UEFI firmware upgrade support'
)
makedepends=(meson valgrind gobject-introspection gtk-doc
             python-cairo noto-fonts noto-fonts-cjk python-gobject vala
             bash-completion python-pillow help2man gnu-efi-libs)
checkdepends=(umockdev)
provides=(libfwupd.so)
backup=('etc/fwupd/daemon.conf'
        'etc/fwupd/redfish.conf'
        'etc/fwupd/remotes.d/dell-esrt.conf'
        'etc/fwupd/remotes.d/fwupd-tests.conf'
        'etc/fwupd/remotes.d/lvfs-testing.conf'
        'etc/fwupd/remotes.d/lvfs.conf'
        'etc/fwupd/remotes.d/vendor-directory.conf'
        'etc/fwupd/remotes.d/vendor.conf'
        'etc/fwupd/thunderbolt.conf'
        'etc/fwupd/uefi_capsule.conf'
)
source=("https://people.freedesktop.org/~hughsient/releases/${pkgname}-${pkgver}.tar.xz"{,.asc})
sha256sums=('ae56ceb44b786f21f54d133ac70bc5d9cb8cd4bda0167339c669a228da67fa3c'
            'SKIP')
validpgpkeys=(163EB50119225DB3DF8F49EA17ACBA8DFA970E17) # Richard Hughes <richard@hughsie.com>

build() {
    arch-meson ${pkgname}-${pkgver} build \
        -D b_lto=false \
        -D plugin_modem_manager=true \
        -D plugin_intel_spi=true \
        -D lzma=true \
        -D docs=gtkdoc \
        -D plugin_flashrom=true \
        -D supported_build=true \
        -D efi_binary=false
    meson compile -C build
}

check() {
    meson test -C build
}

package() {
    DESTDIR="${pkgdir}" meson install -C build
    # Fixup mode to match polkit
    install -d -o root -g 102 -m 750 "${pkgdir}"/usr/share/polkit-1/rules.d
    # Remove the tests
    rm -r "${pkgdir}"/usr/share/installed-tests/
    mv "${pkgdir}"/usr/bin/{,fwupd-}dbxtool
    mv "${pkgdir}"/usr/share/man/man1/{,fwupd-}dbxtool.1
    # Remove msr module-load config as it is built-in
    rm "${pkgdir}"/usr/lib/modules-load.d/fwupd-msr.conf
}
