# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Mirco Tischler <mt-ml at gmx dot de>

pkgname=fwupd
pkgver=1.6.0
pkgrel=2
pkgdesc="Simple daemon to allow session software to update firmware"
arch=(x86_64)
url="https://github.com/fwupd/fwupd"
license=(LGPL)
depends=(libxmlb efivar python libsmbios libgusb
         libsoup json-glib gcab libarchive gpgme
         libgudev polkit shared-mime-info tpm2-tss
         flashrom libjcat fwupd-efi)
optdepends=(
    'modemmanager: modem firmware upgrade support'
    'udisks2: UEFI firmware upgrade support'
)
makedepends=(meson valgrind gobject-introspection gtk-doc
             python-cairo noto-fonts noto-fonts-cjk python-gobject vala
             bash-completion python-pillow help2man gnu-efi-libs)
checkdepends=(umockdev)
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
        'etc/fwupd/upower.conf')
source=("https://people.freedesktop.org/~hughsient/releases/${pkgname}-${pkgver}.tar.xz"{,.asc}
        "fix-efi.patch::$url/commit/197d3dc3b9acb93be30c4a7f49e8c0ad3f554818.patch")
sha256sums=('c4d9c5a870a60517470f7c4d2ae339eccb77bbca5b474c483984d0d4ece33f5e'
            'SKIP'
            'bc166b15607992362723341932cca193cb13c85e84300d42246e7e54a8041aa3')
validpgpkeys=(163EB50119225DB3DF8F49EA17ACBA8DFA970E17) # Richard Hughes <richard@hughsie.com>

prepare() {
    cd ${pkgname}-${pkgver}
    patch -p1 -i ../fix-efi.patch
}

build() {
    arch-meson ${pkgname}-${pkgver} build \
        -D b_lto=false \
        -D plugin_flashrom=true \
        -D supported_build=true \
        -D efi_sbat_distro_id='arch' \
        -D efi_sbat_distro_summary='Arch Linux' \
        -D efi_sbat_distro_pkgname=${pkgname} \
        -D efi_sbat_distro_version=${pkgver} \
        -D efi_sbat_distro_url="https://archlinux.org/packages/community/x86_64/${pkgname}/"
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
